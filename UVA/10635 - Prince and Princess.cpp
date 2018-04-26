#define _CRT_SECURE_NO_WARNINGS
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
int vis[250 * 250 + 5];
int dp[250 * 250 + 5];
int  main()
{
	//freopen("A.txt", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);
	int t,n,a,b,x,tt=1;
	scanf("%d", &t);
	while (t--){
		memset(vis, 0, sizeof(vis));
		memset(dp, 0, sizeof(dp));
		scanf("%d%d%d", &n, &a, &b);
		for (int i = 0; i <= a; i++){
			scanf("%d", &x);
			vis[x] = i+1;
		}
		vector<int > vv;
		for (int i = 0; i <= b; i++){
			scanf("%d", &x);
			if (vis[x])	
				vv.push_back(vis[x]);
		}
		// 4 5 3 2 
		// 2 1 4 3
		// 4 -1 1 3
		int res = 0;
		b = vv.size();
		for (int i = 0; i < b; i++){
			x = lower_bound(dp, dp + res, vv[i]) - dp;
			if (x == res)
				res++;
			dp[x] = vv[i];
		}
		printf("Case %d: %d\n",tt++, res);
	}
	return 0;
}