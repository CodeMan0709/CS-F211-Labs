#include <stdio.h>
//calculating gcd
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
//calculating maximum while removing each val
int max_possible_gcd(int arr[], int n) {
  int max_gcd = 0, removed_idx = -1;

  for (int i = 0; i < n; i++) {
    int gcd_so_far = 0;
    for (int j = 0; j < n; j++) {
      if (j != i) {
        gcd_so_far = gcd(gcd_so_far, arr[j]);
      }
    }
    if (gcd_so_far > max_gcd) {
      max_gcd = gcd_so_far;
      removed_idx = i;
    }
  }

  return max_gcd;
}

int main() {
  int n;
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  printf(" %d \n", max_possible_gcd(arr, n));

  return 0;
}
