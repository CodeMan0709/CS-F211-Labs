// C++ code to implement above approach
#include <bits/stdc++.h>
using namespace std;

// Binary search to find the last occurrence
int nextIndex(int arr[], int N, int l,
			int target)
{
	int result = -1;
	int r = N - 1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (arr[mid] == target) {
			result = mid;
			l = mid + 1;
		}
		else if (arr[mid] > target)
			r = mid - 1;
		else
			l = mid + 1;
	}

	// Result will give the last occurrence &
	// adding one will return next element
	return result + 1;
}

// Function to find the number
// of unique elements
int unique(int arr[], int N)
{
	int i = 0;
	int count = 0;
	while (i < N) {

		// Returns the next element
		i = nextIndex(arr, N, i, arr[i]);
		count++;
	}
	return count;
}

// Driver Code
int main()
{
	int arr[] = { 1, 1, 1, 1, 1, 1, 2, 2, 2,
				2, 3, 5, 5, 7, 7, 8, 8, 9,
				9, 10, 11, 12 };
	int N = sizeof(arr) / sizeof(arr[0]);
	cout << unique(arr, N);
	return 0;
}
