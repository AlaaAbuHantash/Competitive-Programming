#define _CRT_SECURE_NO_WARNINGS
// yes !
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
int a[1001];
int n, m;
long long dp[1001][1001];
long long int calc(int ind, int c) {

	if (ind == n && c == m)
		return 0;
	if (ind > n || c > m)
		return 2000000000000;
	if (dp[ind][c] != -1)
		return dp[ind][c];
	long long res = 2000000000000, r = 0;
	for (int i = ind; i < n; i++) {
		r += a[i];
		res = min(res, max(r, calc(i + 1, c + 1)));
	}
	return dp[ind][c] = res;
}
int main() {
	//freopen("a.txt", "rt", stdin);
	while (scanf("%d%d", &n, &m) > 0) {
		int mm = -1;
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			mm = max(mm, a[i]);
		}
		if (m >= n) {
			printf("%d\n", mm);
			continue;
		}
		printf("%lld\n", calc(0, 0));
	}
}

