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

int geti(){
	int y = 0, s = 1;
	char c = getchar();
	while ( !isdigit(c) && c!='-' ) c = getchar();
	if ( c == '-' ) s = -1 , c = getchar();
	while ( isdigit(c) ) y = y * 10 + ( c - '0' ) , c = getchar();
	return s * y;
}
int n,x; 
vector<int > v;
int dp[105][3];
int calc ( int ind , int sum ){
	if(ind  ==n && sum ==  1 ) return 0;
	else if ( ind == n ) return -oo;
	if (dp[ind ][sum ] != -1 )return dp[ind][sum] ;
	int r = -oo;
	r = max ( r , calc ( ind +1 , sum ));
	r = max ( r , calc ( ind +1 ,( sum + v[ind] )%2 ) + v[ind] );
	return dp[ind][sum]=r;
}
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	scanf("%d",&n) ; 
	mem(dp,-1);
	rep(i,n ) {
		scanf("%d",&x) ; 
		v.push_back(x);
	}
	int res = calc ( 0,0) ; 
	if ( res <0 ) res = 0;
	printf("%d\n",res);
	return 0 ;
}