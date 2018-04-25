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
int t, n, m, x, q, y;
char c, s[60];
vector<int> st;
int a[1024500];
vector<int> u; // s -> set // c -> clear // F  -> filp // N -> nothing
int flip(int v) {
	if (v == 1)
		return 2;
	if (v == 2)
		return 1;
	if (v == 3)
		return 0;
	return 3;
}
void propagate(int p, int l, int r) {
	if (u[p] == 0)
		return;
	if (u[p] == 1)
		st[p] = r - l + 1;
	else if (u[p] == 2)
		st[p] = 0;
	else if (u[p] == 3)
		st[p] = (r - l + 1) - st[p];

	if (l != r) {
		if (u[p] == 1 || u[p] == 2) {
			u[p * 2] = u[p];
			u[(p * 2) + 1] = u[p];
		} else {
			u[p * 2] = flip(u[p * 2]);
			u[(p * 2) + 1] = flip(u[(p * 2) + 1]);
		}
	}
	u[p] = 0;
}
void build(int p, int l, int r) {
	u[p] = 0;
	if (l == r)
		st[p] = a[l];
	else {
		build(p * 2, l, (l + r) / 2);
		build((p * 2) + 1, ((l + r) / 2) + 1, r);
		int p1 = st[p * 2];
		int p2 = st[(p * 2) + 1];
		st[p] = p1 + p2;
	}
}
int calc(int p, int l, int r) {
	if (x > r || y < l)
		return 0;
	propagate(p, l, r);
	if (l >= x && r <= y)
		return st[p];

	return calc(p * 2, l, (l + r) / 2) + calc((p * 2) + 1, ((l + r) / 2) + 1, r);

}

void tree_clear(int p, int l, int r) {
	propagate(p, l, r);
	if (x > r || y < l)
		return;
	if (l == r) {
		st[p] = 0;
	//	u[p] = 0;
		return;
	}
	if (l >= x && r <= y) {
		st[p] =0;
		u[p * 2] = 2;
		u[(p * 2) + 1] = 2;
		return;
	}
	tree_clear(p * 2, l, (l + r) / 2);
	tree_clear((p * 2) + 1, ((l + r) / 2) + 1, r);
	int p1 = st[p * 2];
	int p2 = st[(p * 2) + 1];
	st[p] = p1 + p2;

}
void tree_set(int p, int l, int r) {
	propagate(p, l, r);
	if (x > r || y < l)
		return;
	if (l == r) {
		st[p] = 1;
		return;
	}
	if (l >= x && r <= y) {
		st[p] = r - l + 1;
		u[p * 2] = 1;
		u[(p * 2) + 1] = 1;
		return;
	}
	tree_set(p * 2, l, (l + r) / 2);
	tree_set((p * 2) + 1, ((l + r) / 2) + 1, r);
	int p1 = st[p * 2];
	int p2 = st[(p * 2) + 1];
	st[p] = p1 + p2;

}
void tree_flip(int p, int l, int r) {
	propagate(p, l, r);
	if (x > r || y < l)
		return;
	if (l == r) {
		st[p] = (st[p] == 1 ? 0 : 1);
		return;
	}
	if (l >= x && r <= y) {
		st[p] = r - l + 1 - st[p];
		u[p * 2] = flip(u[p * 2]);
		u[(p * 2) + 1] = flip(u[(p * 2) + 1]);
		return;
	}
	tree_flip(p * 2, l, (l + r) / 2);
	tree_flip((p * 2) + 1, ((l + r) / 2) + 1, r);
	int p1 = st[p * 2];
	int p2 = st[(p * 2) + 1];
	st[p] = p1 + p2;

}

int main() {
	//freopen("test.txt", "rt", stdin);
	int tt = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &m);

		int z = 0;
		for (int i = 0; i < m; i++) {
			scanf("%d%s", &x, s);
			int len = strlen(s);
			for (int j = 0; j < x; j++)
				for (int k = 0; k < len; k++)
					a[z++] = s[k] - '0';
		}
		n = z;
		scanf("%d", &q);
		st.clear();
		st.resize(n * 4);
		u.clear();
		u.resize(n * 4);
		build(1, 0, n - 1);
		printf("Case %d:\n", tt++);
		for (int i = 0, j = 0; i < q; i++) {
			scanf(" %c%d%d", &c, &x, &y);
			if (c == 'F') {
				tree_set(1, 0, n - 1);
			} else if (c == 'E') {
				tree_clear(1, 0, n - 1);
			} else if (c == 'I') {
				tree_flip(1, 0, n - 1);
			} else if (c == 'S') {
				int res = calc(1, 0, n - 1);
				j++;
				printf("Q%d: %d\n", j, res);
			}
		}

	}

	return 0;
}
