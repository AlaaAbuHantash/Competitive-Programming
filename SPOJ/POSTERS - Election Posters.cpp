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
int t, x, y, n, m, nub;

struct s {
	int l, r, u;
	long long res;
};
int a[400004];
vector<s> st;
void build(int p, int l, int r) {
	if (l == r) {
		st[p].l = 0;
		st[p].r = 0;
		st[p].u = 0;
		return;
	}
	build(p * 2, l, (l + r) / 2);
	build(p * 2 + 1, ((l + r) / 2) + 1, r);

}
void pro(int p, int l, int r) {
	if (l == r) {
		st[p].l = st[p].u;
		st[p].r = st[p].u;

	} else {
		st[p * 2].u = st[p].u;
		st[p * 2 + 1].u = st[p].u;
		st[p].l = st[p].u;
		st[p].r = st[p].u;
	}
	st[p].u = 0;
}
void fun(int p, int l, int r) {
	if (st[p].u != 0)
		pro(p, l, r);
	if (r < x || l > y)
		return;
	if (l >= x && r <= y) {
		st[p].u = nub;
		pro(p, l, r);
		return;
	}
	fun(p * 2, l, (l + r) / 2);
	fun(p * 2 + 1, ((l + r) / 2) + 1, r);
	st[p].l = st[p * 2].l;
	st[p].r = st[p * 2 + 1].r;

}
long long res;
void get(int p, int l, int r) {
	if (st[p].u != 0)
		pro(p, l, r);
	if (l == r) {
		if (!a[st[p].l] && st[p].l != 0)
			res++;
		a[st[p].l] = 1;
		return;
	}
	get(p * 2, l, (l + r) / 2);
	get(p * 2 + 1, ((l + r) / 2) + 1, r);
}
int main() {
	//freopen("test.txt", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);

	scanf("%d", &t);
	while (t--) {
		m = 0;
		memset(a, 0, sizeof(a));
		scanf("%d", &n);
		vector<pair<int, int> > v;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &x, &y);
			m = max(m, y);
			x--;
			y--;
			v.push_back(make_pair(x, y));

		}
		nub = 1;
		st.clear();
		st.resize(m * 4);
		build(1, 0, m - 1);
		for (int i = 0; i < n; i++) {
			x = v[i].first;
			y = v[i].second;
			fun(1, 0, m - 1);
			nub++;
		}
		res = 0;
		get(1, 0, m - 1);
		printf("%lld\n", res);

	}
	return 0;
}


