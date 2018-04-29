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
/*
*	You got a dream, you gotta protect it.
*/ 
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair
#define pi 2 * acos(0);
#define eps 1e-6
using namespace std;
int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ;
int d,x,a,b,s1,s2;
vector<pair<int ,int > >v ; 
int dp[241][31] ; 
int calc (int sum , int ind ) {
	if ( sum == x && ind == d) 
		return  1; 
	if ( ind >= d ) 
		return 0;
	if ( dp[sum][ind] != -1 ) 
		return dp[sum][ind];
	int res = 0 ;
	for (int i = v[ind].first ; i<= v[ind].second ; i++) {
		res = max ( res , calc ( sum +i , ind +1 ) ) ;
	}
	return dp[sum][ind] = res;
}
void path (int sum , int ind ) {
	if ( sum == x && ind == d) 
		return  ; 
	int res = 0 ;
	int aa = v[ind].first ;
	for (int i = v[ind].first ; i<= v[ind].second ; i++) {
		if ( res <= calc ( sum +i , ind +1 )) {
			res =  calc ( sum +i , ind +1 ) ; 
			aa = i;
		}
	}
	printf("%d " , aa ) ; 
	path (sum+aa, ind+1);
	return ;
}
int  main()
{	
	//freopen("test.in" , "rt" , stdin);
	scanf("%d%d",&d,&x);
	s1=0;s2=0;
	 mem(dp,-1);
	for(int i=0 ; i<d; i++){
		scanf("%d%d",&a , &b);
		v.push_back(mp(a,b));
	}
	int r = calc ( 0,0) ; 
	if (!r ) 
		printf("NO\n");
	else {
		printf("YES\n"); 
		path (0,0);
		printf("\n");
	}

	return 0 ;
}
