#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
int n, m, s, v;
vector<pair<double, double> > pos;
vector<pair<double, double> > hole;
vector<vector<int> > e;
int id;
int vis[101], match[101];
bool findPath(int nod) {
	vis[nod] = id;
	for (int i = 0; i < e[nod].size(); i++) {
		int x = e[nod][i];
		if (match[x] == -1 || (vis[match[x]] != id && findPath(match[x]))) {
			vis[x] = id;
			match[x] = nod;
			return 1;
		}
	}
	return 0;
}
int maxMatch() {
	int res = 0;
	for (int i = 0; i < n; i++) {
		id++;
		if (findPath(i))
			res++;
	}
	return res;
}
int main(int argc, char **argv) {
	//freopen("a.txt", "r", stdin);
	while (scanf("%d%d%d%d", &n, &m, &s, &v) > 0) {
		hole.clear();
		pos.clear();
		e.clear();
		e.resize(n);
		memset(vis, 0, sizeof(vis));
		memset(match, -1, sizeof(match));

		id = 1;
		for (int i = 0; i < n; i++) {
			double a, b;
			scanf("%lf%lf", &a, &b);
			pos.push_back(mp(a, b));
		}
		for (int i = 0; i < m; i++) {
			double a, b;
			scanf("%lf%lf", &a, &b);
			hole.push_back(mp(a, b));
		}

		for (int i = 0; i < n; i++) {
			double a = pos[i].first;
			double b = pos[i].second;
			for (int j = 0; j < m; j++) {
				double aa = hole[j].first;
				double bb = hole[j].second;
				double dist = sqrt(pow((aa - a), 2.0) + pow((bb - b), 2.0));
				double t = dist / v;
				if (t <= s) {
					e[i].push_back(j);
				}
			}
		}

		printf("%d\n", n - maxMatch());
	}
	return 0;
}
