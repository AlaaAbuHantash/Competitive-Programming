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
/*YOU got a DREAM, YOU gotta protect it. */
using namespace std;

vector<int> st;
int a[100005];
int t, x, y, n, m;
void build(int p, int l, int r) {
	if (l == r) {
		st[p] = a[l];
		return;
	}

	build(p * 2, l, (l + r) / 2);
	build((p * 2) + 1, ((l + r) / 2) + 1, r);
	st[p] = min(st[p * 2], st[p * 2 + 1]);

}
int fun(int p, int l, int r) {
	if (x > r || y < l)
		return 10e9 + 9;
	if (l >= x && r <= y)
		return st[p];

	return min(fun(p * 2, l, (l + r) / 2),
			fun((p * 2) + 1, ((l + r) / 2) + 1, r));

}

int main() {
	//freopen("test.txt", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);
	int tt = 1;
	scanf("%d", &t);
	while (t--) {
		printf("Scenario #%d:\n", tt++);
		scanf("%d%d", &n, &m);
		st.clear();
		st.resize(n * 4);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		build(1, 0, n - 1);
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &x, &y);
			x--;
			y--;
			printf("%d\n", fun(1, 0, n - 1));
		}
	}
	return 0;
}


