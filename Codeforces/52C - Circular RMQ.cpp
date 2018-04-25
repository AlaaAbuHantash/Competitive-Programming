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
using namespace std;
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int n, k, x, y, val;
char cc;
vector<long long> st;
vector<long long> u, uu;
long long a[200005];
void build(int p, int l, int r) {
	if (l == r) {
		u[p] = 0;
		st[p] = a[l];
		return;
	}
	build(p * 2, l, (l + r) / 2);
	build((p * 2) + 1, ((l + r) / 2) + 1, r);
	st[p] = min(st[(p * 2) + 1], st[p * 2]);

}
void pro(int p, int l, int r) {
	if (!u[p])
		return;
	st[p] += u[p];
	if (l != r) {
		u[p * 2] += u[p];
		u[p * 2 + 1] += u[p];
	}
	u[p] = 0;
}
void change(int p, int l, int r) {
	pro(p, l, r);
	if (x > r || y < l)
		return;
	if (l >= x && r <= y) {
		u[p] += val;
		pro(p, l, r);
		return;
	}
	change(p * 2, l, (l + r) / 2);
	change((p * 2) + 1, ((l + r) / 2) + 1, r);
	st[p] = min(st[(p * 2) + 1], st[p * 2]);
}
long long calc(int p, int l, int r) {
	pro(p, l, r);
	if (x > r || y < l)
		return 2e9;
	if (l >= x && r <= y)
		return st[p];
	return min(calc(p * 2, l, (l + r) / 2),
			calc(p * 2 + 1, ((l + r) / 2) + 1, r));
}
int main() {
	//freopen("test.txt", "rt", stdin);

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);

	st.clear();
	st.resize(n * 4);
	u.clear();
	u.resize(n * 4);
	build(1, 0, n - 1);
	scanf("%d", &k);
	int z;
	char s[111];
	gets(s);
	for (int i = 0; i < k; i++) {
		vector<int> z;
		gets(s);
		for (char *v = strtok(s, " "); v != NULL; v = strtok(NULL, " "))
			z.push_back(atoi(v));

		if (z.size() == 2) {
			x = z[0];
			y = z[1];
			long long res = 0;
			if (y < x) {
				int xx = x, yy = y;
				x = 0;
				y = yy;
				res = calc(1, 0, n - 1);
				x = xx;
				y = n - 1;
				res = min(res, calc(1, 0, n - 1));
			} else
				res = calc(1, 0, n - 1);
			printf("%lld\n", res);
		} else {
			x = z[0];
			y = z[1];
			val = z[2];
			if (y < x) {
				int xx = x, yy = y;
				x = 0;
				y = yy;
				change(1, 0, n - 1);
				x = xx;
				y = n - 1;
				change(1, 0, n - 1);
			} else
				change(1, 0, n - 1);

		}
	}

	return 0;
}

