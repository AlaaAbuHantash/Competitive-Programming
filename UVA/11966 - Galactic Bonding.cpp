#include <bits/stdc++.h>
using namespace std;
int p[1001];
int find(int x) {
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}
int main() {
	//freopen("a.txt", "r", stdin);
	int t, tt = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		double d;
		scanf("%d%lf", &n, &d);
		double a, b;
		vector<pair<double, double> > v;
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf", &a, &b);
			v.push_back(make_pair(a, b));
			p[i] = i;
		}
		int ans = n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				double val = sqrt(
						(v[i].first - v[j].first) * (v[i].first - v[j].first)
								+ ((v[i].second - v[j].second)
										* (v[i].second - v[j].second)));
				if (val <= d && p[find(i)] != p[find(j)]) {
					p[find(i)] = p[find(j)];
					ans--;
				}
			}
		printf("Case %d: %d\n", tt++, ans);
	}
	return 0;
}

