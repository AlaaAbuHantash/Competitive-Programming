#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <stack>
#include <cstring>
#include <math.h>
#include<cstdio>
#include<deque>
#include<sstream>
using namespace std;
#define mp make_pair
int r[101][101];
int vis[101][101];
int dx[] = { 0, 0, 0 - 1, 1 };
int dy[] = { -1, 1, 0, 0 };
int main() {

	//freopen("a.txt", "rt", stdin);
	int t, n, m, a, b, aa, bb;
	cin >> t;
	while (t--) {
		cin >> m >> n;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> r[i][j];
		cin >> b >> a >> bb >> aa;
		queue<pair<int, int> > q;
		q.push(mp(a, b));
		int res = !(aa == a && b == bb);
		bool f = 0;
		while (!q.empty()) {
			int siz = q.size();
			while (siz--) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				if (x == aa && y == bb) {
					f = 1;
					break;
				}
				//if (vis[x][y])
				//continue;
				vis[x][y] = 1;
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (nx >= 0 && ny >= 0 && nx < n && ny < m && !r[nx][ny]
							&& !vis[nx][ny]) {
						vis[nx][ny] = 1;
						q.push(mp(nx, ny));
					}
				}
			}
			if (f)
				break;
			res++;
		}
		printf("%d\n", res);
	}
	return 0;
}

