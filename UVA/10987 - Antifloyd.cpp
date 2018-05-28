#include <bits/stdc++.h>
using namespace std;
int v[505][505];
int vis[505][505];
int main(int argc, char **argv) {

	freopen("a.txt", "r", stdin);
	int t, tt = 1;
	scanf("%d", &t);
	while (t--) {
		memset(vis, 0, sizeof(vis));
		memset(v, 0, sizeof(v));
		int n;
		scanf("%d", &n);
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				int x;
				scanf("%d", &x);
				v[j][i] = x;
				v[i][j] = x;
			}
		}

		int c = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j) {
					vis[i][j] = 1, c++;
				}
			}
		}

		bool f = 1;
		for (int k = 0; k < n && f; k++) {
			for (int i = 0; i < n && f; i++)
				for (int j = 0; j < n && f; j++) {
					if (i != j && j != k && i != k) {
						if (v[i][j] > v[i][k] + v[k][j]) {
							f = 0;
							continue;
						}
						if (v[i][j] == v[i][k] + v[k][j]) {
							vis[i][j] = 0;
						}
					}
				}
		}
		int r = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (i != j && vis[i][j])
					r++;
			}
		}
		printf("Case #%d:\n", tt++);
		if (!f)
			puts("Need better measurements.");
		else {
			printf("%d\n", r);
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					if (vis[i][j]) {
						printf("%d %d %d\n", i + 1, j + 1, v[i][j]);
					}
				}
			}
		}
		puts("");
	}
	return 0;
}
