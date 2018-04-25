#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <stack>
#include <cstring>
#include <math.h>
#include<cstdio>
#include<deque>
#include<sstream>
#define mp make_pair
#define eps 1e-6
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int res[77][111];
int c[55], x;
int main() {
	//freopen("A.txt", "rt", stdin);
	int n, m;
	vector<pair<int, int> > a, b, aa;
	while (scanf("%d%d", &m, &n) > 0) {
		if (n + m == 0)
			return 0;
		memset(res, -1, sizeof(res));

		memset(c, 0, sizeof(c));
		int mx = 0;

		a.clear();
		aa.clear();
		b.clear();
		for (int i = 0; i < m; i++) {
			scanf("%d", &x);
			a.push_back(mp(x, i));

			aa.push_back(mp(i, x));
			mx = max(mx, x);
		}

		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			b.push_back(mp(x, i));
			c[i] = x;
		}
		bool f = 1;
		sort(a.rbegin(), a.rend());
		sort(b.rbegin(), b.rend());
		if (mx <= n) {
			for (int i = 0; i < m && f; i++) {
				//cout << a[i].first << " a " << a[i].second << endl;
				for (int j = 0, nxt = 0; j < a[i].first && f; j++) {
					for (int k = nxt; k < n; k++)
						if (b[k].first > 0) {

							b[k].first--;

							res[a[i].second][j] = b[k].second;
							nxt = k + 1;
							break;
						}

					if (res[a[i].second][j] == -1)
						f = 0;
				}
			}
		} else
			f = 0;

		if (f) {
			puts("1");
			for (int i = 0; i < m; i++) {
				printf("%d", res[i][0] + 1);
				for (int j = 1; j < aa[i].second; j++) {
					printf(" %d", res[i][j] + 1);
				}
				puts("");
			}
		} else
			puts("0");
	}

	return 0;
}

