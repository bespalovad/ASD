#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	int n = 0;
	printf ("Enter number of array elements: ");
	scanf ("%d", &n);
	int *arr = (int*) malloc(n*sizeof(int));
	printf ("Enter %d elements:\n", n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &arr[i]);
	}
	int x;
	printf ("Enter searched element: ");
	scanf ("%d", &x);
	int pos = -1;
	int f = 1;
	int mid;
    int low = 0;
    int high = n-1;
    while ((arr[low] < x) & (arr[high] > x) & f) {
        mid = low + ((x - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        if (arr[mid] < x) {
            low = mid + 1;
		}
        if (arr[mid] > x) {
            high = mid - 1;
		}
        if (arr[mid] == x) {
            f = 0;
            pos = mid;
		}
    }
    if (arr[low] == x) {
        pos = low;
        f = 0;
	}
    if (arr[high] == x) {
        pos = high;
        f = 0;
	}
	if (pos == -1) {
		printf ("Element not found\n");
	} else {
		printf ("Element position - %d\n", pos);
	}
	return 0;
}

