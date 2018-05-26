#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {

	//freopen("a.txt", "r", stdin);

	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, t, m, st;
		scanf("%d%d%d%d", &n, &st, &t, &m);
		vector<vector<pair<int, int> > > v(n + 1);
		vector<int> dist(n + 1, 2e9);
		vector<int> vis(n + 1);
		for (int i = 0; i < m; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			v[b].push_back(make_pair(a, c));
		}
		dist[st] = 0;
		priority_queue<pair<int, int> > q;
		q.push(make_pair(0, st));
		while (!q.empty()) {
			int d = -q.top().first;
			int fr = q.top().second;
			vis[fr] = 1;
			q.pop();
			for (int i = 0; i < v[fr].size(); i++) {
				int nod = v[fr][i].first;
				int dd = v[fr][i].second;
				if (!vis[nod] && dd + d < dist[nod]) {
					dist[nod] = dd + d;
					q.push(make_pair(-dist[nod], nod));
				}
			}
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (dist[i + 1] <= t)
				res++;
		}

		printf("%d\n", res);
		if(tc)puts("");

	}
	return 0;
}
