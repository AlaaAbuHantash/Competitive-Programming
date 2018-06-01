#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
int main(int argc, char **argv) {
	//freopen("a.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		vector<pair<pair<int, int>, int> > v;
		int a, b, c;
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &a, &b, &c);
			v.push_back(mp(mp(a, b), c));
		}
		vector<int> dist(n, 1e9);
		dist[0] = 0;
		int up = 1;
		for (int i = 0; i < n && up != -1; i++) {
			up = -1;
			for (int j = 0; j < v.size(); j++) {
				a = v[j].first.first;
				b = v[j].first.second;
				c = v[j].second;
				if (dist[a] != 1e9 && dist[b] > dist[a] + c) {
					dist[b] = dist[a] + c;
					up = i;
				}
			}
		}
		if (up == n - 1)
			puts("possible");
		else
			puts("not possible");
	}
	return 0;
}
