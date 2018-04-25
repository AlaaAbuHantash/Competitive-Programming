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
int n, m, x, y;
struct s {
	int l, cl, r, cr, mid, cmid, res;
};
vector<s> st;
int a[100004];

void build(int p, int l, int r) {

	if (l == r) {
		st[p].cl = 1;
		st[p].cr = 1;
		st[p].cmid = 1;
		st[p].l = a[l];
		st[p].r = a[l];
		st[p].mid = a[l];
		st[p].res = 1;

	} else {
		build(p * 2, l, (l + r) / 2);
		build((p * 2) + 1, ((l + r) / 2) + 1, r);

		if (st[p * 2].mid == st[(p * 2) + 1].mid && st[p * 2].cmid
				&& st[(p * 2) + 1].cmid) {
			st[p].cmid = st[p * 2].cmid + st[(p * 2) + 1].cmid;
			st[p].mid = st[p * 2].mid;
			st[p].l = st[p * 2].mid;
			st[p].r = st[(p * 2) + 1].mid;
			st[p].cl = st[p].cmid; // مش حتفرق
			st[p].cr = st[p].cmid;
			st[p].res = st[p].cmid;
			st[p].res = max(st[p].res, max(st[p * 2].res, st[(p * 2) + 1].res));

		} else if (st[p * 2].mid == st[(p * 2) + 1].l && st[p * 2].cmid) {
			st[p].cmid = 0;
			st[p].mid = 0;
			st[p].l = st[p * 2].l;
			st[p].r = st[(p * 2) + 1].r;
			st[p].cl = st[p * 2].cmid + st[(p * 2) + 1].cl;
			st[p].cr = st[(p * 2) + 1].cr;
			st[p].res = max(st[p].cl, st[p].cr);
			st[p].res = max(st[p].res, max(st[p * 2].res, st[(p * 2) + 1].res));

		} else if (st[p * 2].r == st[(p * 2) + 1].mid && st[(p * 2) + 1].cmid) {

			st[p].cmid = 0;
			st[p].mid = 0;
			st[p].l = st[p * 2].l;
			st[p].r = st[(p * 2) + 1].mid;
			st[p].cl = st[p * 2].cl;
			st[p].cr = st[p * 2].cr + st[(p * 2) + 1].cmid;
			st[p].res = max(st[p].cl, st[p].cr);
			st[p].res = max(st[p].res, max(st[p * 2].res, st[(p * 2) + 1].res));

		} else if (st[p * 2].r == st[(p * 2) + 1].l) {

			st[p].cmid = st[p * 2].cr + st[(p * 2) + 1].cl;
			st[p].mid = st[p * 2].r;
			st[p].l = st[p * 2].l;
			st[p].r = st[(p * 2) + 1].r;
			st[p].cl = st[p * 2].cl;
			st[p].cr = st[(p * 2) + 1].cr;
			st[p].res = max(st[p].cmid, max(st[p].cl, st[p].cr));
			st[p].res = max(st[p].res, max(st[p * 2].res, st[(p * 2) + 1].res));

		} else {
			st[p].cmid = 0;
			st[p].mid = 0;
			st[p].l = st[p * 2].l;
			st[p].r = st[(p * 2) + 1].r;
			st[p].cl = st[p * 2].cl;
			st[p].cr = st[(p * 2) + 1].cr;
			st[p].res = max(st[p * 2].res, st[(p * 2) + 1].res);

		}
	}
	//cout << p << " " << st[p].res << endl;
}
s calc(int p, int l, int r) {
	if (x > r || y < l) {
		s tmpp;
		tmpp.cl = -100001;
		tmpp.cr = -100001;
		tmpp.cmid = -100001;
		tmpp.l = -100001;
		tmpp.r = -100001;
		tmpp.mid = -100001;
		tmpp.res = -100001;
		return tmpp;
	}
	if (l >= x && r <= y) {
		return st[p];
	}

	s s1 = calc(p * 2, l, (l + r) / 2);
	s s2 = calc((p * 2) + 1, ((l + r) / 2) + 1, r);
	s tmp;

	if (s1.mid == s2.mid && s1.cmid && s2.cmid) {
		tmp.cmid = s1.cmid + s2.cmid;
		tmp.mid = s1.mid;
		tmp.l = s1.mid;
		tmp.r = s2.mid;
		tmp.cl = tmp.cmid; // مش حتفرق
		tmp.cr = tmp.cmid;
		tmp.res = tmp.cmid;
		tmp.res = max(tmp.res, max(s1.res, s2.res));

	} else if (s1.mid == s2.l && s1.cmid) {
		tmp.cmid = 0;
		tmp.mid = 0;
		tmp.l = s1.l;
		tmp.r = s2.r;
		tmp.cl = s1.cmid + s2.cl;
		tmp.cr = s2.cr;
		tmp.res = max(tmp.cl, tmp.cr);
		tmp.res = max(tmp.res, max(s1.res, s2.res));

	} else if (s1.r == s2.mid && s2.cmid) {

		tmp.cmid = 0;
		tmp.mid = 0;
		tmp.l = s1.l;
		tmp.r = s2.mid;
		tmp.cl = s1.cl;
		tmp.cr = s1.cr + s2.cmid;
		tmp.res = max(tmp.cl, tmp.cr);
		tmp.res = max(tmp.res, max(s1.res, s2.res));

	} else if (s1.r == s2.l) {

		tmp.cmid = s1.cr + s2.cl;
		tmp.mid = s1.r;
		tmp.l = s1.l;
		tmp.r = s2.r;
		tmp.cl = s1.cl;
		tmp.cr = s2.cr;
		tmp.res = max(tmp.cmid, max(tmp.cl, tmp.cr));
		tmp.res = max(tmp.res, max(s1.res, s2.res));

	} else {
		tmp.cmid = 0;
		tmp.mid = 0;
		tmp.l = s1.l;
		tmp.r = s2.r;
		tmp.cl = s1.cl;
		tmp.cr = s2.cr;
		tmp.res = max(s1.res, s2.res);

	}

	return tmp;

}

int main() {
	//freopen("test.txt", "rt", stdin);

	while (scanf("%d", &n) > 0) {
		if (!n)
			break;
		scanf("%d", &m);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		st.clear();
		st.resize(n * 4);
		build(1, 0, n - 1);
		for (int i = 0, j = 0; i < m; i++) {
			scanf("%d%d", &x, &y);
			x--;
			y--;
			int res = calc(1, 0, n - 1).res;
			printf("%d\n", res);

		}
	}

	return 0;
}

