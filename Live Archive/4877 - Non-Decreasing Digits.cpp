#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip> 
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
long long  dp[66][11];
int n; 
long long  calc(int ind, int nub){
	
	if (ind == 0)
		return 1;
	if (dp[ind][nub] != -1)
		return dp[ind][nub];
	long long  res = 0;
	for (int i = nub; i < 10; i++){
		res+=calc(ind - 1, i);
	}
	return dp[ind][nub]=res;
}
int  main()
{
	//freopen("myfile.txt", "w", stdout);
	int t,tt;
	memset(dp, -1, sizeof(dp));
	scanf("%d", &t);
	while (t--){
		scanf("%d%d",&tt, &n);
		printf("%d %lld\n", tt, calc(n, 0));

	}
	return 0;
}