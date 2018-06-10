#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int a[100003];
int cnt[100003];
int main() {
	//freopen("input", "rt", stdin);
	int n, m;
	cin >> n >> m;
	vector<int> v(n), res(m);
	vector<pair<int, int> > r;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] < 100001)
			cnt[v[i]]++;
	}
	int x, y, mx = 0;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		r.push_back(make_pair(x, y));
		mx = max(mx, y - x + 1);
	}

	for (int i = 1; i <= mx; i++)
		if (cnt[i] >= i) {
			a[0] = 0;
			for (int j = 0; j < n; j++)
				a[j + 1] = a[j] + (i == v[j]);

			for (int j = 0; j < m; j++) {
				x = r[j].first;
				y = r[j].second;
				if (a[y] - a[x - 1] == i)
					res[j]++;
			}

		}
	for (int i = 0; i < m; i++) {
		cout << res[i] << "\n";
	}
	return 0;
}

