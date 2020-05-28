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
	int s = -1;
	int b = 0;
	int e = n;
	int k = (n+1)/2 - 1;
	while (s != k) {
		if (s < k) {
			s++;
			b = s;
		}
		if (s > k) {
			e = s;
			s = b;
		}
		for (int i = b+1; i < e; i++) {
			if (arr[i] < arr[s]) {
				int t = arr[i];
				arr[i] = arr[s+1];
				arr[s+1] = arr[s];
				arr[s] = t;
				s++;
			}
		}
	}
	printf ("Median = %d\n", arr[s]);
	return 0;
}

