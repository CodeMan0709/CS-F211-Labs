#include <stdio.h>
#define MAXN 1000005

int n, k, a[MAXN], cnt[MAXN];
long long ans;

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        cnt[i] = cnt[i-1] + (a[i] % 2 == 1);
    }
    int l = 0, r = 0, odd = 0;
    while (r <= n) {
        if (odd < k) {
            ++r;
            odd += (a[r] % 2 == 1);
        } else if (odd > k) {
            ++l;
            odd -= (a[l] % 2 == 1);
        } else {
            ans += n - r + 1;
            ++l;
            odd -= (a[l] % 2 == 1);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
