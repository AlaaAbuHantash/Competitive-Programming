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
using namespace std;
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int a[111];
int v[111][111];
int main() {
	//freopen("test.txt", "rt", stdin);

	int n, m, x, y;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i + 1];

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		v[x][y] = 1;
		v[y][x] = 1;
	}
	int res = 2e9;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (v[i][j] == 1) {
				for (int k = 1; k <= n; k++)
					if (v[j][k] && v[k][i]) {
						res = min(res, a[i] + a[k] + a[j]);
					}
			}
		}
	}
	if (res == 2e9)
		res = -1;
	cout << res << endl;
	return 0;
}

