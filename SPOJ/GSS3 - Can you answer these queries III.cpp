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
int n, q, x, y;

int a[50005];
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
	res.mid = p1.mid + p2.mid;
	res.maxsum = max(p1.right + p2.left, max(p1.maxsum, p2.maxsum));
	res.left = max(p1.left, p1.mid + p2.left);
	res.right = max(p1.right + p2.mid, p2.right);
	return res;

}
void update(int p, int l, int r) {
	if (x > r || x < l) {
		return;
	}
	if (l == r) {
		if (l == x)
			a[l] = y;
		st[p].left = a[l];
		st[p].right = a[l];
		st[p].mid = a[l];
		st[p].maxsum = a[l];
		return;
	}

	update(p * 2, l, (l + r) / 2);
	update((p * 2) + 1, ((l + r) / 2) + 1, r);

	st[p].mid = st[p * 2].mid + st[(p * 2) + 1].mid;
	st[p].maxsum = max(st[p * 2].right + st[(p * 2) + 1].left,
			max(st[p * 2].maxsum, st[(p * 2) + 1].maxsum));
	st[p].left = max(st[p * 2].left, st[p * 2].mid + st[(p * 2) + 1].left);
	st[p].right = max(st[(p * 2) + 1].right,
			st[(p * 2) + 1].mid + st[p * 2].right);
	return;
}
int main() {
	//freopen("test.txt", "rt", stdin);
	non.right = -50000;
	non.left = -50000;
	non.mid = -50000;
	non.maxsum = -50000;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &q);
	st.clear();
	st.resize(n * 4);
	build(1, 0, n - 1);
	int z;
	for (int i = 0; i < q; i++) {
		scanf("%d%d%d", &z, &x, &y);
		//cout << z << " " << x << " " << y << endl;
		x--;
		if (z) {
			y--;
			printf("%d\n", calc(1, 0, n - 1).maxsum);
		} else
			update(1, 0, n - 1);
	}

	return 0;
}

