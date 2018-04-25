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

/*YOU got a DREAM, YOU gotta protect it. */
using namespace std;
int t, n, x, y;

vector<int> st;
vector<int> u;
void pro(int p, int l, int r) {
	if (u[p] == 0)
		return;
	if (l == r) {
		st[p] += u[p];
	}
	if (l != r) {
		st[p] += u[p];
		u[p * 2] += u[p];
		u[(p * 2) + 1] += u[p];

	}
	u[p] = 0;
}
void update(int p, int l, int r) {
	//cout << p << " " << l << " " << r << endl;
	pro(p, l, r);
	if (x > r || y < l)
		return;

	if (x <= l && r <= y) {
		u[p]++;
		//cout << " l r " << l << " " << r << " " << u[p] << endl;
		pro(p, l, r);
		return;
	}
	update(p * 2, l, (l + r) / 2);
	update(p * 2 + 1, ((l + r) / 2) + 1, r);
	st[p] = max(st[p * 2], st[p * 2 + 1]);
	//cout << " hhh " << st[p * 2] << " -- " << st[p * 2 + 1] << endl;
	//cout << " res " << st[p] << " - " << p << " " << u[p] << endl;
}
int main() {
	//freopen("test.txt", "rt", stdin);

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		vector<pair<int, int> > v;
		int m = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &x, &y);
			v.push_back(make_pair(x, y));
			m = max(m, y);
		}

		st.clear();
		st.resize(m * 4);
		u.clear();
		u.resize(m * 4);
		for (int i = 0; i < n; i++) {
			x = v[i].first;
			y = v[i].second;
			update(1, 0, m);
		}
		printf("%d\n", st[1]);
	}
	return 0;
}

