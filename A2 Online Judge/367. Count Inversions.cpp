#include <cstdio>
#include <cstring>

long long mergeAndCountSplitInv(int *A, int *helper, int low, int mid,
		int high) {
	memcpy(helper + low, A + low, (high - low + 1) * sizeof(int));
	int i = low, j = mid + 1, k = low;
	long long split = 0;

	while (i <= mid && j <= high) {
		if (helper[i] <= helper[j])
			A[k] = helper[i++];
		else {
			A[k] = helper[j++];
			split += mid + 1 - i;
		}
		k++;
	}

	while (i <= mid)
		A[k++] = helper[i++];

	return split;
}

long long auxCountInversion(int *A, int *helper, int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		long long left = auxCountInversion(A, helper, low, mid);
		long long right = auxCountInversion(A, helper, mid + 1, high);
		long long split = mergeAndCountSplitInv(A, helper, low, mid, high);
		return left + right + split;
	}
	return 0;
}

long long countInversion(int *A, int N) {
	int *helper = new int[N];
	return auxCountInversion(A, helper, 0, N - 1);
}

int main() {
	int *A, N, i;
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &N);
		A = new int[N];
		for (i = 0; i < N; i++)
			scanf("%d", &A[i]);

		printf("%lld\n", countInversion(A, N));
	}
	return 0;
}
