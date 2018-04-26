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
#define mp make_pair
#define eps 1e-6
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
map<int, int> a;
int vis[1111];
int t, n, x, y, tt = 1;
vector<pair<int, int> > p;
void path(int beg, int ind) {
	for (int i = 0; i < n; i++)
		if (!vis[i] && p[i].first == beg) {
			vis[i] = 1;
			path(p[i].second, i);
		} else if (!vis[i] && p[i].second == beg) {
			//	printf("%d %d\n", p[i].second, p[i].first);
			vis[i] = 1;
			path(p[i].first, i);
		}

	if (p[ind].first == beg)
		printf("%d %d\n", p[ind].first, p[ind].second);
	else
		printf("%d %d\n", p[ind].second, p[ind].first);

}
int main() {
	//freopen("A.txt", "rt", stdin);
	bool g = 0;
	scanf("%d", &t);
	while (t--) {
		if (g)
			puts("");
		g = 1;
		memset(vis, 0, sizeof(vis));
		scanf("%d", &n);
		a.clear();
		p.clear();
		vector<int> v;

		for (int i = 0; i < n; i++) {
			scanf("%d%d", &x, &y);
			if (!a[x])
				v.push_back(x);
			a[x]++;
			if (!a[y])
				v.push_back(y);
			a[y]++;
			p.push_back(mp(x, y));
		}
		bool f = 1;

		for (int i = 0; i < v.size() && f; ++i)
			if (a[v[i]] & 1)
				f = 0;

		printf("Case #%d\n", tt++);
		if (!f)
			puts("some beads may be lost");
		else {
			//printf("%d %d\n", p[0].first, p[0].second);
			vis[0] = 1;
			path(p[0].second, 0);
		}
	}
	return 0;
}

