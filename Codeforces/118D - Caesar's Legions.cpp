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
int n1,n2,k1,k2;
long long dp[101][101][11][11];
long long calc ( int x , int y , int a , int b) {
	if ( x > n1 || n2 < y || a > k1 || b > k2 )  return 0 ;
	if ( x == n1 && y ==n2 ) return 1 ;
	if(dp[x][y][a][b]!=-1)
		return dp[x][y][a][b];
	long long res =calc(x+1 , y , a+1 , 0 ) %100000000 + calc (x , y+1 , 0 , b+1) %100000000;
	return dp[x][y][a][b]=res %100000000 ;
}
int  main()
{	
	//freopen("test.in" , "rt" , stdin);
	mem(dp,-1);
	scanf("%d%d%d%d",&n1,&n2,&k1,&k2);
	printf("%lld\n",calc(0,0,0,0));
	return 0 ;
}