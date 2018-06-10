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
	You got a dream, you gotta protect it.
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
 int a[3],n;
 int dp[4001][4001];
 int calc (int len ,int x ) {
	 if ( len == 0 ) 
		 return 0;
	 if ( len < 0 ) 
		 return -oo ;
	 if ( dp[len][x] != -1 ) 
		 return dp[len][x];
	 int res= -oo;
	 for (int i =0; i < 3 ; i++)
		  res=max ( res , calc ( len - a[i] , i ) +1 ); 
	 return dp[len][x]=res;
 }
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	scanf("%d%d%d%d",&n,&a[0],&a[1],&a[2]);
	mem(dp,-1);
	printf("%d\n",calc (n,0));
	return 0 ;
}