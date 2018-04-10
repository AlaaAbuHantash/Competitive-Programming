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
vector<int> v;
vector<pair<int, int> > p;
int t, n, m, l, x, a, b;
int adj[105][105];
int dp[1005][105];
int tar;
int calc(int ind, int sum) {
	if (sum == 0 && ind == m )
		return 0;
	if (sum < 0 || ind > m)
		return 100000;
	if (dp[sum][ind] != -1)
		return dp[sum][ind];
	int r = 2e9 ;
	r = min ( r, calc(ind + 1, sum - p[ind].second) + p[ind].first);
	r = min(r, calc(ind + 1, sum));
	return dp[sum][ind] = r;
}
int main() {

	//freopen("b.txt", "rt", stdin);
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &m, &l);
		v.clear();
		p.clear();
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			v.push_back(x - 1);
		}
		memset(dp, -1, sizeof(dp));
		memset(adj, 0, sizeof(adj));
		sort(v.begin(), v.end());
		int r = v[n - 1] - v[0];
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &a, &b);
			p.push_back(mp(a, b));
			//cout << a << "  * " << b << endl;
		}

		calc(0, r);
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++) {
				int tar = abs(v[i] - v[j]);
				int res = calc(0, tar);
				//cout << tar << " " <<res << endl;
				if (res <= l) {
					adj[i][j] = 1;
					adj[j][i] = 1;
				} else {
					adj[j][i] = 0;
					adj[i][j] = 0;
				}
			}

		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) {
					if (adj[i][k] && adj[k][j])
						if (!adj[i][j] || adj[i][k] + adj[k][j] < adj[i][j] )
							adj[i][j] = adj[i][k] + adj[k][j];
				}

		if (!adj[0][n - 1])
			puts("-1");
		else
			printf("%d\n", adj[0][n - 1]);
	}
	return 0;
}


