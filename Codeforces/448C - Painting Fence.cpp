#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
int n;
int a[5005];
int dp[5005][5005];
int calc(int cur, int lst) {
	if (cur == n + 1)
		return 0;
	if (dp[cur][lst] != -1)
		return dp[cur][lst];
	int res = 1e9;
	if (a[cur] >= a[lst]) {
		res = min(res, calc(cur + 1, lst) + 1); // up
		res = min(res, calc(cur + 1, cur) + a[cur] - a[lst]);
	} else {
		res = min(res, calc(cur + 1, cur));
	}
	return dp[cur][lst] = res;
}
int main(int argc, char **argv) {
	//freopen("a.txt", "r", stdin);
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	printf("%d\n", calc(1, 0));
	return 0;
}
