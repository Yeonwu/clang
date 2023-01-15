# include <stdio.h>

int min[200000], max[200000];

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void sortmax(int* max, int p) {
	while (max[p/2] < max[p] && p != 0) {
		swap(&max[p/2], &max[p]);
		p /= 2;
	}
}

void sortmin (int* min, int p) {
	while (min[p/2] > min[p] && p != 0) {
		swap(&min[p/2], &min[p]);
		p /= 2;
	}
}

void print_arr(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	int n, i, maxtop = 0, mintop = 0, p;
	int max[100000] = {0}, min[100000] = {0};
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		if (maxtop > mintop) {
			p = maxtop;
			scanf("%d", &max[maxtop]);
			sortmax(max, p);
		} else {
			p = mintop;
			scanf("%d", &min[mintop];
			sortmin(min, p);
		}
		if (min[mintop] > min[mintop]) {
			swap(&min[mintop], &min[mintop]);
		}
	}

	return 0;
}