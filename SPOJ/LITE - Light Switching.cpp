#include <iostream>
#include<stdio.h>
#include<string>
#include <cstring>
#include<stack>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
vector<pair<int, int> > st;
int n, m, z, x, y;
void build(int p, int l, int r) {
	if (l == r) {
		st[p].first = 0;
		st[p].second = 0;
		return;
	}
	build(p * 2, l, (l + r) / 2);
	build(p * 2 + 1, ((l + r) / 2) + 1, r);
}
void pro(int p, int l, int r) {

	st[p].first = r - l + 1 - st[p].first;
	if (l != r) {
		st[p * 2].second = !st[p * 2].second;
		st[p * 2 + 1].second = !st[p * 2 + 1].second;
	}
	st[p].second = 0;
}
void update(int p, int l, int r) {
	if (st[p].second)
		pro(p, l, r);
	if (x > r || y < l)
		return;
	if (l >= x && y >= r) {

		pro(p, l, r);
		return;
	}
	update(p * 2, l, (l + r) / 2);
	update(p * 2 + 1, ((l + r) / 2) + 1, r);
	st[p].first = st[p * 2].first + st[p * 2 + 1].first;

}
int calc(int p, int l, int r) {
	if (st[p].second)
		pro(p, l, r);
	if (x > r || y < l)
		return 0;
	if (l >= x && y >= r)
		return st[p].first;

	return calc(p * 2, l, (l + r) / 2) + calc(p * 2 + 1, ((l + r) / 2) + 1, r);
}
int main() {
	//freopen("test.txt", "rt", stdin);

	scanf("%d%d", &n, &m);
	st.resize(n * 4);
	build(1, 0, n - 1);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &z, &x, &y);
		x--;
		y--;
		if (z)
			printf("%d\n", calc(1, 0, n - 1));
		else
			update(1, 0, n - 1);
	}

	return 0;
}

