#include <bits/stdc++.h>
using namespace std;
int p[100005];
int find(int x) {
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}
int main() {
	freopen("a.txt", "r", stdin);
	int a, b;
	vector<pair<int, int> > v;
	while (cin >> a) {
		if (a == -1) {
			int ans = 0;
			for (int i = 0; i < v.size(); i++) {
				int aa = find(p[v[i].first]);
				int bb = find(p[v[i].second]);
				if (aa == bb)
					continue;
				ans++;
				p[aa] = p[bb];
			}

			printf("%d\n", (int) v.size() - ans);
			v.clear();
		} else {
			scanf("%d", &b);
			v.push_back(make_pair(a, b));
			p[a] = a;
			p[b] = b;
		}
	}
	return 0;
}

