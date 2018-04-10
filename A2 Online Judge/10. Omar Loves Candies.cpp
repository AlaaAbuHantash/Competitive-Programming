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
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int b[1002][1002];
int a[1002][1002];
int main() {
	//freopen("test.txt", "rt", stdin);
	int t, n, m, x;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);

		for (int i = 0; i <= n + 1; ++i)
			for (int j = 0; j <= m + 1; ++j)
				b[i][j] = 0;
		int res = -2e9;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				scanf("%d", &a[i][j]);
				if (a[i][j] > res)
					res = a[i][j];
			}

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1]
						+ a[i - 1][j - 1];

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				int sum = b[n][m] - b[n - i][m] - b[n][m - j] + b[n - i][m - j];
				if (sum > res)
					res = sum;
			}
		printf("%d\n", res);
	}
	return 0;
}

