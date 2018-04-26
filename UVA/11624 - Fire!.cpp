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

string s;
vector<string> v;
int vis[1001][1001];
int main() {
	//freopen("A.txt", "rt", stdin);
	int t, n, m;
	scanf("%d", &t);
	queue<pair<pair<int, int>, int> > q;
	vector<pair<int, int> > vv;
	while (t--) {
		memset(vis, 0, sizeof(vis));
		scanf("%d%d", &n, &m);
		v.clear();
		vv.clear();
		for (int i = 0; i < n; i++) {
			cin >> s;

			for (int j = 0; j < m; j++) {
				if (s[j] == 'J') {
					q.push(mp(mp(i, j), 1));
					s[j] = '.';
					vis[i][j] = 1;
				} else if (s[j] == 'F') {
					vv.push_back(mp(i, j));
					vis[i][j] = 1;
				}
			}
			v.push_back(s);
		}
		for (int i = 0; i < vv.size(); i++)
			q.push(mp(mp(vv[i].first, vv[i].second), 2));

		bool f = 0;
		int lev = 0;
		while (!q.empty()) {
			int siz = q.size();
			while (siz--) {
				int x = q.front().first.first;
				int y = q.front().first.second;
				int l = q.front().second;
				//cout << x << " " << y << " " << l << endl;
				q.pop();
				if (l == 1)
					if (x < 0 || y < 0 || x >= n || y >= m) {
						f = 1;
						break;
					}
				if (vis[x][y] == 2 && l == 1)
					continue;
				//vis[x][y] = 1;
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];

					if (l == 1 && nx >= 0 && ny >= 0 && nx < n && ny < m
							&& v[nx][ny] != 'F' && v[nx][ny] != '#'
							&& !vis[nx][ny]) {
						vis[nx][ny] = 1;
						q.push(mp(mp(nx, ny), l));
					} else if (l == 2 && nx >= 0 && ny >= 0 && nx < n && ny < m
							&& v[nx][ny] != 'F' && v[nx][ny] != '#'
							&& vis[nx][ny] != 2) {
						vis[nx][ny] = 2;
						q.push(mp(mp(nx, ny), l));
					} else if (l == 1
							&& (nx < 0 || ny < 0 || nx >= n || ny >= m))
						q.push(mp(mp(nx, ny), l));
				}
			}
			if (f)
				break;
			lev++;
		}
		if (f)
			printf("%d\n", lev);
		else
			puts("IMPOSSIBLE");

		while(!q.empty())
			q.pop();

	}
	return 0;
}

