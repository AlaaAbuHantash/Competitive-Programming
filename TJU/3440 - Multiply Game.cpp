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
/*  You got a dream, you gotta protect it.*/
using namespace std;
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int t, n, q, x, z, y;
const int m = 1000000007;
int a[50005];
vector<long long > st;
void build(int p, int l, int r) {
	if (l == r) {
		st[p] = a[l];
		return;
	}
	build(p * 2, l, (l + r) / 2);
	build(p * 2 + 1, ((l + r) / 2) + 1, r);
	st[p] = (st[p * 2] % m * st[p * 2 + 1] % m) % m;
}
void update(int p, int l, int r) {
	if (l > x || r < x)
		return;
	if (l == r && r == x) {
		a[l] = y%m;
		st[p] = a[l]%m;
		return;
	}
	update(p * 2, l, (l + r) / 2);
	update(p * 2 + 1, ((l + r) / 2) + 1, r);
	st[p] = (st[p * 2] % m * st[p * 2 + 1] % m) % m;
}

long long  get(int p, int l, int r) {
	if (l > y || r < x)
		return 1;
	if (x <= l && r <= y)
		return st[p]%m;

	long long  p1 = get(p * 2, l, (l + r) / 2)%m;
	long long  p2 = get(p * 2 + 1, ((l + r) / 2) + 1, r)%m;
	return (p1 % m * p2 % m) % m;
}
int main() {
	//freopen("test.txt", "rt", stdin);

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		st.clear();
		st.resize(4 * n);
		build(1, 0, n - 1);
		scanf("%d", &q);
		for (int i = 0; i < q; i++) {
			scanf("%d%d%d", &z, &x, &y);
			x--;
			if (z)
				update(1, 0, n - 1);
			else {
				y--;
				long long  res = get(1, 0, n - 1)%m;
				printf("%lld\n", res % m);
			}
		}

	}
	return 0;
}
