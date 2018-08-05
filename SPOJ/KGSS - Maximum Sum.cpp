#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
int n, a[100005];
pair<int, int> res[100005 * 4];

pair<int, int> getMax(pair<int, int> &a, pair<int, int> &b) {
	vector<int> v(4);
	v[0] = a.first;
	v[1] = a.second;
	v[2] = b.first;
	v[3] = b.second;
	sort(v.begin(), v.end());
	return make_pair(v[2], v[3]);
}
void build(int p, int l, int r) {
	if (l == r) {
		res[p].first = a[l];
		res[p].second = -1;
		return;
	}
	int mid = (r + l) / 2;
	build(p * 2, l, mid);
	build(p * 2 + 1, mid + 1, r);
	res[p] = getMax(res[p * 2], res[p * 2 + 1]);
}
pair<int, int> get(int p, int l, int r, int &a, int &b) {
	if (r < a || l > b)
		return make_pair(-1, -1);
	if (l >= a && r <= b)
		return res[p];
	int mid = (l + r) / 2;
	pair<int, int> aa = get(p * 2, l, mid, a, b);
	pair<int, int> bb = get(p * 2 + 1, mid + 1, r, a, b);
	return getMax(aa, bb);
}
void update(int p, int l, int r, int &ind, int &val) {
	if (ind > r || ind < l)
		return;
	if (l == ind && l == r)  {
		res[p].first = val;
		return;
	}
	int mid = (r + l) / 2;
	update(p * 2, l, mid, ind, val);
	update(p * 2 + 1, mid + 1, r, ind, val);
	res[p] = getMax(res[p * 2], res[p * 2 + 1]);

}
int main() {
	//freopen("a.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	build(1, 0, n - 1);
	int q;
	scanf("%d", &q);
	while (q--) {
		char ch;
		int a, b;
		scanf(" %c%d%d", &ch, &a, &b);
		if (ch == 'U') {
			a--;
			update(1, 0, n - 1, a, b);
		} else {
			a--, b--;
			pair<int, int> r = get(1, 0, n - 1, a, b);
			printf("%d\n", r.first + r.second);
		}
	}
}

