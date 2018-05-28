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
#define eps 1e-9
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int n, m;
int a[12], b[12], c[12], d[12];
int dp[1002][1002][12];
int calc(int sum, int ind, int cnt) {

	if (ind > m || sum <= 0) {
		return 0;
	}
	if (dp[sum][cnt][ind] != -1)
		return dp[sum][cnt][ind];
	int res = 0;

	res = max(res, calc(sum, ind + 1, 0));
	if (a[ind] - b[ind] >= 0) {
		a[ind] -= b[ind];
		if (sum - c[ind] >= 0)
			res = max(res, calc(sum - c[ind], ind, cnt + 1) + d[ind]);
		a[ind] += b[ind];
	}
	return dp[sum][cnt][ind] = res;
}
int main() {
	//freopen("test.txt", "rt", stdin);
	memset(dp, -1, sizeof(dp));
	scanf("%d%d%d%d", &n, &m, &c[0], &d[0]);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
	}
	printf("%d\n", calc(n, 0, 0));
	return 0;
}

