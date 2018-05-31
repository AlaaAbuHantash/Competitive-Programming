#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
int p[1004];
int find(int x) {
	if (x == p[x])
		return x;
	return p[x] = find(p[x]);
}
int main(int argc, char **argv) {
	//freopen("a.txt", "r", stdin);
	int n, m, x, y;
	scanf("%d%d", &n, &m);
	if (m + 1 != n) {
		puts("no");
		return 0;
	}
	for (int i = 0; i < n; i++)
		p[i] = i;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		x--, y--;
		int xx = find(x);
		int yy = find(y);
		if (xx != yy) {
			p[xx] = p[yy];
		} else {
			puts("no");
			return 0;
		}
	}
	puts("yes");
	return 0;
}
