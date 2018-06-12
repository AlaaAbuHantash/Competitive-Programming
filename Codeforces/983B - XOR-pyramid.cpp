#include <bits/stdc++.h>
using namespace std;

int n, q;
int val[5005][5005];
int main(int argc, char **argv) {
	//freopen("a.txt", "r", stdin);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &val[0][i]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n - i; j++) {
			val[i][j] = val[i - 1][j] ^ val[i - 1][j + 1];
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			val[i][j] = max(val[i][j], max(val[i - 1][j], val[i - 1][j + 1]));
		}
	}

	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", val[r - l][l - 1]);
	}

	return 0;
}
