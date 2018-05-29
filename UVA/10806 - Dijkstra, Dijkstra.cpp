#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
int n, m;
struct st {
	int from, to, cap, cost;
	st(int a, int b, int c, int d) :
			from(a), to(b), cap(c), cost(d) {
	}
};
vector<st> v;
int p[1001];
int c[1001];
int src, ed;
int getpath() {

	for (int i = 1; i <= n; i++) {
		c[i] = 1e9;
		p[i] = -1;
	}
	c[src] = 0;
	bool f = 1;
	for (int i = 0; i < n && f; i++) {
		f = 0;
		for (int j = 0; j < v.size(); j++) {
			int a = v[j].from;
			int b = v[j].to;
			int x = v[j].cap;
			int d = v[j].cost;
			if (x && c[a] < 1e9 && c[a] + d < c[b]) {
				c[b] = c[a] + d;
				p[b] = j;
				f = 1;
			}
		}
	}
	return c[ed] < 1e9;
}
void maxflow() {
	int minCost = 0;
	int k = 2;
	src = 1;
	ed = n;
	while (k--) {
		int r = getpath();
		if (!r) {
			puts("Back to jail");
			return;
		}

		int nod = ed;
		while (nod != src) {
			v[p[nod]].cap--;
			v[p[nod] ^ 1].cap++;
			nod = v[p[nod]].from;
		}

		minCost += c[ed];

	}
	printf("%d\n", minCost);
}
int main(int argc, char **argv) {

	//freopen("a.txt", "r", stdin);
	while (scanf("%d", &n) && n) {
		scanf("%d", &m);
		int a, b, c;
		v.clear();
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &a, &b, &c);
			v.push_back(st(a, b, 1, c));
			v.push_back(st(b, a, 0, -c));

			v.push_back(st(b, a, 1, c));
			v.push_back(st(a, b, 0, -c));
		}
		maxflow();
	}
	return 0;
}
