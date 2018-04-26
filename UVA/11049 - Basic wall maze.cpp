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
#define mp make_pair
#define eps 1e-6
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int can[11][11][11][11];
int vis[11][11];
pair<int, int> p[11][11];
int main() {
	//freopen("A.txt", "rt", stdin);
	int t, n, m, x, y;
	int a, aa, b, bb;

	while (scanf("%d%d", &n, &m) > 0) {
		queue<pair<int, int> > q;
		if (n + m == 0)
			return 0;

		q.push(mp(n, m));
		memset(can, 0, sizeof(can));
		memset(vis, 0, sizeof(vis));
		scanf("%d%d", &x, &y);
		for (int k = 0; k < 3; k++) {
			scanf("%d%d%d%d", &a, &b, &aa, &bb);

			if (a == aa) {
				//0 0 1 0
				// 1 5 1 6
				for (int i = b + 1; i <= bb; i++)
					can[a][i][a + 1][i] = -1;
			} else if (b == bb) {
				// 1 5 3 5
				for (int i = a + 1; i <= aa; i++)
					can[i][b][i][b + 1] = -1;
			}
		}
		p[n][m] = mp(-1, -1);
		while (!q.empty()) {
			int frx = q.front().first;
			int fry = q.front().second;
			//cout << frx << " " << fry << endl;
			q.pop();
			if (frx == x && fry == y) {
				break;
			}
			if (vis[frx][fry])
				continue;
			vis[frx][fry] = 1;
			for (int i = 0; i < 4; i++) {
				int nx = frx + dx[i];
				int ny = fry + dy[i];
				if (nx >= 1 && ny >= 1 && nx <= 6 && ny <= 6 && !vis[nx][ny]) {
					if (can[frx][fry][nx][ny] != -1
							&& can[nx][ny][frx][fry] != -1) {
						q.push(mp(nx, ny));
						p[nx][ny] = mp(frx, fry);
					}
				}
			}
		}

		string s = "";
		while (p[x][y].first != -1) {
			//	cin >> x;
			int xx = p[x][y].first;
			int yy = p[x][y].second;
			//cout << x << " " << y << endl;
			//cout << xx << " " << yy << endl;
			if (x == xx) {
				if (y == yy - 1)
					s = "N" + s;
				else
					s = "S" + s;
			} else if (y == yy) {
				// up down
				if (x == xx - 1)
					s = "W" + s;
				else
					s = "E" + s;

			}
			x = xx;
			y = yy;
		}
		cout << s;
		puts("");

	}

	return 0;
}

