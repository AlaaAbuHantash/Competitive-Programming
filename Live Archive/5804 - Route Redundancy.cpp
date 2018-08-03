#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
int tt, a, b, n, m;
vector<vector<int> > v;
vector<int> vis;
int vs;
vector<int> p;
int cap[1005][1005];
int org[1005][1005];
int dfs(int x, int hav) {
	if (x == b) {
		return hav;
	}
	vis[x] = vs;
	int ans = 0;
	for (int i = 0; i < v[x].size(); i++) {
		int nxt = v[x][i];
		if (vis[nxt] != vs && cap[x][nxt] > 0) {
			p[nxt] = x;
			ans = max(ans, dfs(nxt, min(hav, cap[x][nxt])));
			if (ans)
				return ans;

		}
	}
	return ans;
}

double calc() {
	vs = 1;
	vis.clear();
	p.clear();
	vis.resize(n);
	p.resize(n, -1);
	int flow = 0;
	int mx = 0;
	while (true) {
		int res = dfs(a, 20000);
		vs++;
		if (!res)
			break;
		int cur = b;
		int val = org[p[cur]][cur];
		do {
			val = min(val, org[p[cur]][cur]);
			cap[p[cur]][cur] -= res;
			cap[cur][p[cur]] += res;
			cur = p[cur];

		} while (cur != a);
		flow += res;
		mx = max(val, mx);

	}
	//cout << mx << endl;
	if (mx == 0)
		return 0;
	return flow / (double) mx;
}
int main() {
	//freopen("a.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(cap, 0, sizeof(cap));
		scanf("%d%d%d%d%d", &tt, &n, &m, &a, &b);
		v.clear();
		v.resize(n);
		for (int i = 0; i < m; i++) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			v[x].push_back(y);
			v[y].push_back(x);
			cap[x][y] += z;
			org[x][y] = cap[x][y];
		}

		printf("%d %.3lf\n", tt, calc());
	}

}

