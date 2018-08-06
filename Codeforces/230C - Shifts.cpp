#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
int main() {
	//freopen("a.txt", "r", stdin);

	int n, m;
	scanf("%d%d", &n, &m);
	string s;
	vector<vector<int> > v(n);
	for (int i = 0; i < n; i++) {
		cin >> s;
		int f = 0;
		for (int j = 0; j < m; j++) {
			if (s[j] == '1') {
				v[i].push_back(j);
				f = 1;
			}
		}
		if (!f) {
			puts("-1");
			return 0;
		}

	}

	int res = 2e9;
	for (int j = 0; j < m; j++) {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int x = lower_bound(v[i].begin(), v[i].end(), j) - v[i].begin();

			if (x >= 0 && x < v[i].size() && v[i][x] == j)
				continue;
			else {
				if (x == v[i].size())
					x--;
				int y = x - 1;
				if (y == -1)
					y = v[i].size() - 1;
				int aa = abs(j - v[i][x]);
				aa = min(aa, abs(j - v[i][y]));
				aa = min(aa, abs(j + m - v[i][x]));
				aa = min(aa, abs(j + m - v[i][y]));
				aa = min(aa, abs(m - j + v[i][x]));
				aa = min(aa, abs(m - j + v[i][y]));
				aa = min(aa, abs(m - j + v[i][0]));
				aa = min(aa, abs(j + m - v[i][0]));
				aa = min(aa, abs(j - v[i][0]));
				ans += aa;
			}
		}
		res = min(ans, res);

	}
	printf("%d\n", res);

	return 0;
}

