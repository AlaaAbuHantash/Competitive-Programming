#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<set>
using namespace std;
#define eps 1e-9
#define mp make_pair
int dx[] = { -1, 0, 0, 1, 1, 1, -1, -1 };
int dy[] = { 0, -1, 1, 0, 1, -1, 1, -1 };
vector<pair<int, pair<int, int> > > p;
vector<vector<int> > vv;
int v[55];
int vis[55];
bool f = 1;
int main() {
	//freopen("input", "rt", stdin);
	int n, k, a, b;

	cin >> n >> k;
	vv.resize(50);
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		vv[a].push_back(b);
		vv[b].push_back(a);
	}
	vector<int> vt;

	for (int i = 1; i <= n && f; i++) {
		if (!vis[i] && vv[i].size() == 2) {
			int x = vv[i][0];
			int y = vv[i][1];

			if (!vis[x] && !vis[y] && vv[x].size() == 0 && vv[y].size() == 0) {
				p.push_back(mp(i, mp(x, y)));

			} else if (!vis[x] && !vis[y]) {

				if (vv[x].size() == 2) {
					if ((vv[x][0] == y || vv[x][0] == i)
							&& (vv[x][1] == y || vv[x][1] == i)) {
						p.push_back(mp(i, mp(x, y)));

					} else
						f = 0;
				} else if (vv[x].size() == 1) {
					if (vv[x][0] == y || vv[x][0] == i)
						p.push_back(mp(i, mp(x, y)));
				} else if (vv[x].size() > 2)
					f = 0;

				if (vv[y].size() == 1) {
					if (vv[y][0] == x || vv[y][0] == i)
						p.push_back(mp(i, mp(x, y)));
				} else if (vv[y].size() > 2)
					f = 0;
			} else
				f = 0;
			vis[i] = 1;
			vis[x] = 1;
			vis[y] = 1;
		} else if (vv[i].size() > 2)
			f = 0;
	}

	for (int i = 1; i <= n && f; i++)
		if (!vis[i] && vv[i].size() == 1) {
			vis[i] = 1;
			int x = vv[i][0];
			if (!vis[x] && vv[x].size() == 1) {
				vis[x] = 1;
				for (int j = 1; j <= n; j++) {
					if (!vis[j] && vv[j].size() == 0) {
						p.push_back(mp(j, mp(x, i)));
						vis[j] = 1;
						break;
					}
				}
			} else if (!vis[x] && vv[x].size() == 2) {
				int y;
				vis[x] = 1;
				if (vv[x][0] != i)
					y = vv[x][0];
				if (vv[x][1] != i)
					y = vv[x][1];

				if (!vis[y] && vv[y].size() == 1) {
					p.push_back(mp(i, mp(x, y)));
					vis[y] = 1;
				} else
					f = 0;

			}
		}

	if (f) {
		for (int i = 1; i <= n && f; i++) {
			if (vt.size() == 3) {
				if (vv[v[0]].size() == 0 && vv[v[1]].size() == 0
						&& vv[v[2]].size() == 0)
					p.push_back(mp(vt[0], mp(vt[1], vt[2])));
				else
					f = 0;
				vt.clear();
			}
			if (!vis[i])
				vt.push_back(i);
		}
		if (vt.size() == 3 && f) {
			p.push_back(mp(vt[0], mp(vt[1], vt[2])));
			vt.clear();
		}
		if (p.size() * 3 == n)  {
			for (int i = 0; i < p.size(); i++)
				printf("%d %d %d\n", p[i].first, p[i].second.first,
						p[i].second.second);
		} else
			puts("-1");

	} else
		puts("-1");
	return 0;
}

