#include <bits/stdc++.h>
using namespace std;
map<string, int> m;
struct edge {
	string a, b;
	int c;

	bool operator <(edge X) const {
		if (m[b] != m[X.b])
			return m[b] > m[X.b];
		return m[a] < m[X.a];
	}
} E;
int main() {

	freopen("a.txt", "r", stdin);

	int tt = 1;
	int t;
	scanf("%d", &t);
	while (t--) {
		m.clear();
		int n;
		scanf("%d", &n);
		int ind = 0;
		string s;
		map<int, string> rev;
		for (int i = 0; i < n; i++) {
			cin >> s;
			m[s] = ind;
			rev[ind] = s;
			ind++;
		}
		int r;
		scanf("%d", &r);
		string a, b;
		int c;

		vector<edge> v;
		for (int i = 0; i < r; i++) {
			cin >> a >> b >> c;
			E.a = a;
			E.b = b;
			E.c = c;
			v.push_back(E);
		}
		sort(v.begin(), v.end());
		vector<int> ans(n);
		vector<int> dist(n, -1);
		dist[m["Calgary"]] = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < v.size(); j++) {
				int aa = m[v[j].a];
				int bb = m[v[j].b];
				int cc = v[j].c;
				//cout << aa << " " << bb << " " << rev[aa] << " " << rev[bb]<< " " << cc << " " << dist[bb] << " " << dist[aa]<< endl;
				if (dist[aa] != -1
						&& (dist[bb] == -1 || dist[aa] + cc < dist[bb])) {
					dist[bb] = dist[aa] + cc;
					//cout << " in  " << endl;
				}
			}
			ans[i] = dist[m["Fredericton"]];
			//cout << i << "-> " << ans[i] << endl;
		}
		int q;
		scanf("%d", &q);
		printf("Scenario #%d\n", tt++);
		for (int i = 0; i < q; i++) {
			int x;
			scanf("%d", &x);
			if (x >= n - 1)
				x = n - 2;
			if (ans[x] == -1)
				puts("No satisfactory flights");
			else {
				printf("Total cost of flight(s) is $%d\n", ans[x]);
			}
		}
		if (t)
			puts("");
	}
	return 0;
}

