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
int n, m, x, y, z;
struct s {
	int a, b, c;
	int cnt;
};
vector<s> st;
int a[100004];
vector<int> u;
void propagate(int p, int l, int r) {
	if (u[p] == 0)
		return;
	int rr = u[p] % 3;

	if (l == r) {
		a[l] += u[p];
		st[p].a = 0;
		st[p].b = 0;
		st[p].c = 0;
		if (a[l] % 3 == 0)
			st[p].a = 1;
		else if (a[l] % 3 == 2)
			st[p].b = 1;
		else if (a[l] % 3 == 1)
			st[p].c = 1;
	}
	if (l != r) {
		for (int i = 0; i < rr; i++) {
			int tmp = st[p].a;
			st[p].a = st[p].b;
			st[p].b = st[p].c;
			st[p].c = tmp;
		}
		u[p * 2] += u[p]; // cost me 3 WA -_-
		u[(p * 2) + 1] += u[p];
	}
	u[p] = 0;

}
void build(int p, int l, int r) {
	u[p] = 0;
	if (l == r) {
		st[p].a = 1;
		st[p].b = 0;
		st[p].c = 0;
	} else {
		build(p * 2, l, (l + r) / 2);
		build((p * 2) + 1, ((l + r) / 2) + 1, r);
		st[p].a = st[p * 2].a + st[(p * 2) + 1].a;
		st[p].b = st[p * 2].b + st[(p * 2) + 1].b;
		st[p].c = st[p * 2].c + st[(p * 2) + 1].c;

	}
}
int calc(int p, int l, int r) {
	if (x > r || y < l)
		return 0;
	propagate(p, l, r);

	if (l >= x && r <= y) {
		return st[p].a;
	}

	return calc(p * 2, l, (l + r) / 2) + calc((p * 2) + 1, ((l + r) / 2) + 1, r);

}

void tree_set(int p, int l, int r) {
	propagate(p, l, r);
	if (x > r || y < l)
		return;
	if (l >= x && r <= y) {
		u[p]++;
		u[p] %= 3;
		propagate(p, l, r);
		return;
	}
	tree_set(p * 2, l, (l + r) / 2);
	tree_set((p * 2) + 1, ((l + r) / 2) + 1, r);
	st[p].a = st[p * 2].a + st[(p * 2) + 1].a;
	st[p].b = st[p * 2].b + st[(p * 2) + 1].b;
	st[p].c = st[p * 2].c + st[(p * 2) + 1].c;

}
int main() {
	//freopen("test.txt", "rt", stdin);
	scanf("%d%d", &n, &m);
	st.clear();
	st.resize(n * 4);
	u.clear();
	u.resize(n * 4);
	build(1, 0, n - 1);
	for (int i = 0, j = 0; i < m; i++) {
		scanf("%d%d%d", &z, &x, &y);

		if (z == 0)
			tree_set(1, 0, n - 1);
		else {
			int res = calc(1, 0, n - 1);
			printf("%d\n", res);
		}
	}

	return 0;
}