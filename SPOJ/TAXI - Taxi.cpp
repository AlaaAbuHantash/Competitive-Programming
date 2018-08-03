#include <bits/stdc++.h>
using namespace std;
int n, m, s, c;
vector<vector<int> > v;
int match[444];
int vis[444];
int vs;
bool findMatch(int u) {
	vis[u] = vs;
	for (int i = 0; i < (int) v[u].size(); i++) {
		int nod = v[u][i];
		if (match[nod] == -1
				|| (vis[match[nod]] != vs && findMatch(match[nod]))) {
			match[nod] = u;
			return true;
		}
	}
	return false;
}
int maxMatching() {
	int cnt = 0;
	vs = 1;
	memset(match, -1, sizeof(match));
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++) {
		vs++;
		if (findMatch(i)) {
			cnt++;
		}

	}
	return cnt;
}
int main() {
	//freopen("a.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d", &n, &m, &s, &c);
		vector<pair<int, int> > a(n);
		vector<pair<int, int> > b(m);
		v.clear();
		v.resize(n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a[i].first, &a[i].second);
		}
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &b[i].first, &b[i].second);
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				int dist = abs(a[i].first - b[j].first)
						+ abs(a[i].second - b[j].second);
				if (dist * 200 <= s * c)
					v[i].push_back(j);
			}

		printf("%d\n", maxMatching());
	}
	return 0;
}

