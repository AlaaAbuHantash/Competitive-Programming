#include <bits/stdc++.h>
using namespace std;
int a[30003], b[30003];
int main(int argc, char **argv) {
	//freopen("a.txt", "r", stdin);
	int t, n, m;
	scanf("%d", &t);
	while (t--) {

		memset(b, 0, sizeof(b));
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}

		for (int i = 0; i < m; i++) {
			int x;
			scanf("%d", &x);
			b[x]++;
		}
		priority_queue<int> x, y;
		int cur = 1;
		for (int i = 0; i <= n; i++) {
			while (b[i]--) {
				printf("%d\n", x.top());
				if (y.size()) {
					x.push(-y.top());
					y.pop();
				}
				cur++;
			}
			if( i == n ) break;
			x.push(a[i]);
			if (x.size() > cur) {
				y.push(-x.top());
				x.pop();
			}

		}
		if (t)
			puts("");

	}

	return 0;
}
