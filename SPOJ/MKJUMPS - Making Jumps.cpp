#include <bits/stdc++.h>
using namespace std;
int vis[15][15];
int in[15][15];
int n;
int dx[] = { -2, -2, -1, -1, +1, +1, +2, +2 };
int dy[] = { -1, +1, -2, +2, -2, +2, -1, +1 };
int mx;
void calc(int x, int y, int cnt) {
	mx = max(mx, cnt);
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < 10 && ny < 10 && in[nx][ny]
				&& !vis[nx][ny]) {
			vis[nx][ny] = 1;
			calc(nx, ny, cnt + 1);
			vis[nx][ny] = 0;
		}
	}
}
int main() {
	//freopen("a.txt", "r", stdin);
	int tt = 1;
	while (cin >> n && n) {
		int a, b, st;
		int c = 0;
		mx = 0;
		memset(vis, 0, sizeof(vis));
		memset(in, 0, sizeof(in));
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a, &b);
			if (i == 0)
				st = a;
			for (int j = 0; j < b; j++) {
				in[i][j + a] = 1;
				c++;
			}
		}

		vis[0][st] = 1;
		calc(0, st, 1);

		if (c-mx == 1)
			printf("Case %d, %d square can not be reached.\n", tt++, c-mx);
		else
			printf("Case %d, %d squares can not be reached.\n", tt++, c-mx);
	}
	return 0;
}

