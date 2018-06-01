#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
int cum[201];
int freq[201];
map<int, int> m;
int main(int argc, char **argv) {
	//freopen("a.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, x, y;
		scanf("%d", &n);
		vector<int> v;
		vector<pair<int, int> > r;
		memset(freq, 0, sizeof(freq));
		memset(cum, 0, sizeof(cum));
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &x, &y);
			v.push_back(x);
			v.push_back(y);
			r.push_back(mp(x, y));
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) {
			m[v[i]] = i + 1;
		}
		for (int i = 0; i < n; i++) {
			int a = r[i].first;
			int b = r[i].second;
			freq[m[a]]++;
			freq[m[b] + 1]--;
		}
		int mx = 0;
		for (int i = 1; i <= v.size() + 2; i++) {
			cum[i] = cum[i - 1] + freq[i - 1];
			mx = max(mx, cum[i]);
		}
		printf("%d\n", mx);

	}

	return 0;
}
