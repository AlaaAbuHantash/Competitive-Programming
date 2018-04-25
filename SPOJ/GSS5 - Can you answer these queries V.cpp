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
int n, q, x, y, x2, y2;

int a[10005];
struct ST {
	int left, right, mid, maxsum;
};
vector<ST> st;
void build(int p, int l, int r) {
	if (l == r) {
		st[p].left = a[l];
		st[p].right = a[l];
		st[p].mid = a[l];
		st[p].maxsum = a[l];
		return;
	}

	build(p * 2, l, (l + r) / 2);
	build((p * 2) + 1, ((l + r) / 2) + 1, r);

	st[p].mid = st[p * 2].mid + st[(p * 2) + 1].mid;
	st[p].maxsum = max(st[p * 2].right + st[(p * 2) + 1].left,
			max(st[p * 2].maxsum, st[(p * 2) + 1].maxsum));
	st[p].left = max(st[p * 2].left, st[p * 2].mid + st[(p * 2) + 1].left);
	st[p].right = max(st[(p * 2) + 1].right,
			st[(p * 2) + 1].mid + st[p * 2].right);
	return;
}
ST non;
ST calc(int p, int l, int r) {
	if (x > r || y < l) {
		return non;
	}
	if (l >= x && r <= y)
		return st[p];

	ST p1, p2, res;

	p1 = calc(p * 2, l, (l + r) / 2);
	p2 = calc((p * 2) + 1, ((l + r) / 2) + 1, r);
	if (p1.left == -2e9) {
		res.mid = p2.mid;
		res.maxsum = p2.maxsum;
		res.left = p2.left;
		res.right = p2.right;
	} else if (p2.left == -2e9) {
		res.mid = p1.mid;
		res.maxsum = p1.maxsum;
		res.left = p1.left;
		res.right = p1.right;
	} else {
		res.mid = p1.mid + p2.mid;
		res.maxsum = max(p1.right + p2.left, max(p1.maxsum, p2.maxsum));
		res.left = max(p1.left, p1.mid + p2.left);
		res.right = max(p1.right + p2.mid, p2.right);
	}
	return res;

}

int main() {
	//freopen("test.txt", "rt", stdin);

	non.right = -2e9;
	non.left = -2e9;
	non.mid = -2e9;
	non.maxsum = -2e9;
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);

		scanf("%d", &q);
		st.clear();
		st.resize(n * 4);
		build(1, 0, n - 1);
		for (int i = 0; i < q; i++) {
			int x1, y1;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			x1--;
			y1--;
			x2--;
			y2--;
			if (x1 == x2 && y1 == y2) {
				x = x1;
				y = y2;
				int r1 = calc(1, 0, n - 1).maxsum;
				printf("%d\n", r1);
			} else if (x2 > y1) {
				x = x1;
				y = y1;
				int r1 = calc(1, 0, n - 1).right;
				x = x2;
				y = y2;
				int r2 = calc(1, 0, n - 1).left;
				int r3 = 0;
				if (y1 + 1 <= x2 - 1) {
					x = y1 + 1;
					y = x2 - 1;
					r3 = calc(1, 0, n - 1).mid;
				}
				printf("%d\n", r1 + r2 + r3);
			} else {
				int res = -2e9, r1, r2;
				//case 1
				if (x2 - 1 < x1)
					r1 = 0;
				else {
					x = x1;
					y = x2 - 1;
					r1 = calc(1, 0, n - 1).right;
				}
				x = x2;
				y = y2;
				r2 = calc(1, 0, n - 1).left;
				res = max(res, r1 + r2);

				// case 2
				x = x1;
				y = y1;
				r1 = calc(1, 0, n - 1).right;
				if (y1 + 1 > y2)
					r2 = 0;
				else {
					x = y1 + 1;
					y = y2;
					r2 = calc(1, 0, n - 1).left;
				}
				res = max(res, r1 + r2);
				// case 3
				x = x2;
				y = y1;
				r1 = calc(1, 0, n - 1).maxsum;
				res = max(res, r1);
				// case 4
				x = x1;
				y = x2;
				r1 = calc(1, 0, n - 1).right;

				if (x2 + 1 > y2)
					r2 = 0;
				else {
					x = x2 + 1;
					y = y2;
					r2 = calc(1, 0, n - 1).left;
				}
				res = max(res, r1 + r2);

				printf("%d\n", res);
			}

		}
	}

	return 0;
}

