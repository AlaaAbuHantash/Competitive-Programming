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
int n, k, x, y;
char cc;
vector<int> st;
int a[100004];
void build(int p, int l, int r) {
	if (l == r) {
		if (a[l] == 0)
			st[p] = 0;
		else if (a[l] > 0) {
			st[p] = 1;
			a[l] = 1;
		} else {
			st[p] = -1;
			a[l] = -1;
		}
		return;
	}

	build(p * 2, l, (l + r) / 2);
	build((p * 2) + 1, ((l + r) / 2) + 1, r);
	st[p] = st[(p * 2) + 1] * st[p * 2];

}

void change(int p, int l, int r) {

	if (x > r || x < l)
		return;
	if (r == l) {
		if (l == x) {
			a[l] = y;
			if (a[l] == 0)
				st[p] = 0;
			else if (a[l] > 0) {
				st[p] = 1;
				a[l] = 1;
			} else {
				st[p] = -1;
				a[l] = -1;
			}
		}
		return;
	}
	change(p * 2, l, (l + r) / 2);
	change((p * 2) + 1, ((l + r) / 2) + 1, r);
	st[p] = st[(p * 2) + 1] * st[p * 2];
}
int calc(int p, int l, int r) {
//	pro(p, l, r);
	if (x > r || y < l)
		return 1;
	if (l >= x && r <= y)
		return st[p];
	return calc(p * 2, l, (l + r) / 2) * calc((p * 2) + 1, ((l + r) / 2) + 1, r);

}
int main() {
	//freopen("test.txt", "rt", stdin);

	while (scanf("%d%d", &n, &k) > 0) {
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		st.clear();
		st.resize(n * 4);
		build(1, 0, n - 1);
		for (int i = 0; i < k; i++) {
			scanf(" %c%d%d", &cc, &x, &y);
			if (cc == 'P') {
				x--;
				y--;
				int res = calc(1, 0, n - 1);
				if (res == 0)
					printf("0");
				else if (res > 0)
					printf("+");
				else
					printf("-");
			} else {
				x--;
				if (y > 0)
					y = 1;
				else if (y < 0)
					y = -1;

				if (y != a[x])
					change(1, 0, n - 1);
			}

		}
		puts("");
	}

	return 0;
}
