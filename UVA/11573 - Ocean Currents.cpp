#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
char dist[1001][1001];
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
pair<int, int> v[1001][1001];
int main(int argc, char **argv) {
	//freopen("a.txt", "r", stdin);
	int n, m;
	while (scanf("%d%d", &n, &m) > 0) {

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				char c;
				scanf(" %c", &c);
				int a = i + dx[c - '0'];
				int b = j + dy[c - '0'];
				v[i][j] = mp(a, b);

			}

		int k;
		scanf("%d", &k);
		for (int r = 0; r < k; r++) {
			int a, b, x, y, aa, bb;
			scanf("%d%d%d%d", &a, &b, &aa, &bb);
			a--, b--, bb--, aa--;
			deque<pair<int, int> > q;
			memset(dist, -1, sizeof(dist));
			q.push_back(mp(a, b));
			dist[a][b] = 0;
			while (!q.empty()) {
				a = q.front().first;
				b = q.front().second;
				q.pop_front();
				if (a == aa && b == bb) {
					break;
				}
				x = v[a][b].first;
				y = v[a][b].second;
				if (x >= 0 && y >= 0 && x < n && y < m
						&& (dist[x][y] == -1 || dist[x][y] > dist[a][b])) {
					dist[x][y] = dist[a][b];
					q.push_front(mp(x, y));
				}

				for (int i = 0; i < 8; i++) {
					x = dx[i] + a;
					y = dy[i] + b;
					if (x >= 0 && y >= 0 && x < n && y < m
							&& (dist[x][y] == -1 || dist[x][y] > dist[a][b] + 1)) {
						dist[x][y] = dist[a][b] + 1;
						q.push_back(mp(x, y));
					}
				}
			}
			printf("%d\n", dist[aa][bb]);

			while (!q.empty()) {
				q.pop_back();
			}

		}
	}
	return 0;
}
