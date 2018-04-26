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
#define mp make_pair
#define eps 1e-6
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int a[105][105];
int n;
int dp[105][105];
int calc(int x, int y) {
	if (x == n)
		return 0;
	if (y >= n || y < 0)
		return -2000;
	if (dp[x][y] != -1)
		return dp[x][y];
	int r = 0;
	r = max(r, calc(x + 1, y) + a[x][y]);
	r = max(r, calc(x + 1, y + 1) + a[x][y]);
	r = max(r, calc(x + 1, y - 1) + a[x][y]);
	return dp[x][y] = r;
}
int main() {
	//freopen("a.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);
	while (cin >> n && n) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];
		memset(dp, -1, sizeof(dp));
		int res = 0;
		for (int i = 0; i < n; i++)
			res = max(res, calc(0, i));
		printf("%d\n", res);
	}
	return 0;
}

