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
int t, x, y, z, n, q, val;
vector<long long> st, u;
int a[100005];
void pro(int p, int l, int r) {
	if (!u[p])
		return;
	st[p] += u[p] * (r - l + 1);
	if (l != r) {
		u[p * 2] += u[p];
		u[p * 2 + 1] += u[p];
	}
	u[p] = 0;
}
void update(int p, int l, int r) {
	pro(p, l, r);
	if (r < x || l > y)
		return;
	if (l >= x && r <= y) {
		u[p] += val;
		pro(p, l, r);
		return;
	}
	update(p * 2, l, (l + r) / 2);
	update(p * 2 + 1, ((l + r) / 2) + 1, r);
	st[p] = st[p * 2] + st[p * 2 + 1];

}
long long get(int p, int l, int r) {
	pro(p, l, r);
	if (r < x || l > y)
		return 0;
	if (l >= x && r <= y) {
		return st[p];
	}
	long long aa, bb;
	aa = get(p * 2, l, (l + r) / 2);
	bb = get(p * 2 + 1, ((l + r) / 2) + 1, r);
	return aa + bb;
}
int main() {
	//freopen("test.txt", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);

	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &q);
		memset(a, 0, sizeof(a));
		st.clear();
		st.resize(n * 4);
		u.clear();
		u.resize(n * 4);
		for (int i = 0; i < q; i++) {
			scanf("%d%d%d", &z, &x, &y);
			x--;
			y--;
			if (z) {
				printf("%lld\n", get(1, 0, n - 1));
			} else {
				scanf("%d", &val);
				update(1, 0, n - 1);
			}
		}
	}
	return 0;
}


