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
int n, m;
int a[100005];
long long b[100005];
long long dp[100005];
int vis[100005], id;
long long calc(int ind) {
	if (ind >= m)
		return 0;
	if (vis[ind] == id)
		return dp[ind];
	vis[ind] = id;
	return dp[ind] = max(calc(ind + 2) + a[ind], calc(ind + 1));

}
long long calc2(int ind) {
	if (ind >= n)
		return 0;
	if (vis[ind] == id)
		return dp[ind];
	vis[ind] = id;
	return dp[ind] = max(calc2(ind + 2) + b[ind], calc2(ind + 1));
}
int main() {
	//freopen("A.txt", "rt", stdin);
	id = 1;
	while (scanf("%d%d", &n, &m) > 0) {
		if (n + m == 0)
			break;
		for (int i = 0; i < n; i++) {
			id++;
			for (int j = 0; j < m; j++)
				scanf("%d", &a[j]);
			b[i] = calc(0);
		}
		id++;
		printf("%lld\n", calc2(0));
	}
	return 0;
}
