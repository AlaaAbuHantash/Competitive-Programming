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
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
#define mp make_pair
using namespace std;
int dp[1111][1111];
int x = 1000000000 + 7, n, t;
int calc(int ind, int nub) {

	if (ind == n)
		return 1;
	int res = 0;
	if (dp[ind][nub] != -1)
		return dp[ind][nub];
	if (nub != 1)
		res = (res + calc(ind + 1, 1)) % x;
	res = (res + calc(ind + 1, 0)) % x;
	return dp[ind][nub] = res % x;
}
int main() {
	//freopen("input", "rt", stdin);
	scanf("%d", &t);
	while (t--) {
		memset(dp, -1, sizeof(dp));
		scanf("%d", &n);
		cout << (calc(1, 1) + calc(1, 0)) % x << endl;
	}
	return 0;
}

