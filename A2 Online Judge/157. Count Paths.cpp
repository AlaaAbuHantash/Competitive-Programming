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
int dp[105][105];
 int n,m,a,b;
int countpath(int x,int y){
	 //cout << x << " " << y << endl;
	if(x==n && y== m )
		return 1;

	if (x>n|| y>m)
		return 0;

	if(dp[x][y]!=-1)
		return dp[x][y];

	dp[x][y] = countpath(x+1,y)%1000000007 + countpath(x,y+1)%1000000007;
	return dp[x][y] ;
 }

int  main()
{

	//freopen("test.in" , "rt" , stdin);
	while(scanf("%d%d",&n,&m)>0){
		if(n<0&&m<0)break;
		a=max(n,m);
		b=min(n,m);
		n=a;
		m=b;
		mem(dp,-1);
		int res = countpath(0,0)%1000000007;
		printf("%d\n",res);
	}
	return 0 ;
}