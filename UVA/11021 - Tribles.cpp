#include <bits/stdc++.h>
using namespace std;
double x[1005];
int n, k, m;
double dp[1005];
int vis[1005];
double calc(int mm) {
	if (mm == 0)
		return x[0];
	if (mm < 0)
		return 0;
	double res = 0;
	if (vis[mm])
		return dp[mm];
	for (int i = 0; i < n; i++) {
		double tmp = x[i] * pow(calc(mm - 1), i);
		res = res + tmp;
	}
	vis[mm] = 1;
	return dp[mm] = res;
}
int main(int argc, char **argv) {
	//freopen("a.txt", "r", stdin);
	int t, tt = 1;
	scanf("%d", &t);
	while (t--) {
		memset(vis, 0, sizeof(vis));
		scanf("%d%d%d", &n, &k, &m);
		for (int i = 0; i < n; i++) {
			cin >> x[i];
		}
		printf("Case #%d: %.6f\n", tt++, pow(calc(m - 1), k));
	}
	return 0;
}

