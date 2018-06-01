#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
int n;
int a[200002];
int res[200002 * 4];
void build(int p, int st, int ed) {
	if (st == ed) {
		res[p] = a[st];
		return;
	}
	int mid = (st + ed) / 2;
	build(p * 2, st, mid);
	build(p * 2 + 1, mid + 1, ed);
	res[p] = res[p * 2] + res[p * 2 + 1];
}
int get(int p, int l, int r, int st, int ed) {
	if (ed < l || r < st)
		return 0;
	if (st >= l && ed <= r)
		return res[p];
	int mid = (st + ed) / 2;
	int lsum = get(p * 2, l, r, st, mid);
	int rsum = get(p * 2 + 1, l, r, mid + 1, ed);
	return lsum + rsum;

}
void update(int p, int x, int val, int st, int ed) {
	if (x < st || ed < x)
		return;
	if (st == ed) {
		a[x] = val;
		res[p] = val;
		return;
	}
	int mid = (st + ed) / 2;
	update(p * 2, x, val, st, mid);
	update(p * 2 + 1, x, val, mid + 1, ed);
	res[p] = res[p * 2] + res[p * 2 + 1];

}
int main(int argc, char **argv) {
	//freopen("a.txt", "r", stdin);
	int t = 0;
	while (scanf("%d", &n) && n) {
		if (t)
			puts("");
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		build(1, 0, n - 1);
		string s;
		printf("Case %d:\n", ++t);
		while (cin >> s) {
			if (s[0] == 'M') {
				int l, r;
				scanf("%d%d", &l, &r);
				l--, r--;
				printf("%d\n", get(1, l, r, 0, n - 1));

			} else if (s[0] == 'S') {
				int pos, val;
				scanf("%d%d", &pos, &val);
				pos--;
				update(1, pos, val, 0, n - 1);

			} else
				break;
		}
	}
	return 0;
}
