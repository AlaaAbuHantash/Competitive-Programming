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
#define eps 1e-9



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
int n,t,x,r,fres,ft; 
int dp[1005][105],v1[105][105],v2[105][105],vis[105];
int   calc (int a , int c  ){
	int res=oo;
	if ( c <0  )
		return oo;

	if(a==n-1)
		return 0 ; 


	if(dp[c][a] != -1 )
		return dp[c][a];

	rep(i,n)
		if ( i != a )
			res = min ( res ,  calc(i,c-v1[a][i])+ v2[a][i]);	

	dp[c][a]=res ;
	return res;
}
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	while(scanf("%d%d",&n,&t)>0){
		if ( !n ) break;
		mem(dp,-1);
		rep(i,n)
			rep(j,n){
				scanf("%d",&x);
				v1[i][j]=x;
		}

		rep(i,n)
			rep(j,n){
				scanf("%d",&x);
				v2[i][j]=x;
		}

		fres=oo;
		ft=t;
		vis[0]=1;
		r=calc(0,t);
		while(true)
		{
			if(calc(0,ft-1) == r)
				ft--;
			else 
				break;
			if(ft == 0)
				break;
		}
		printf("%d %d\n",r,ft);
	}
	return 0 ;
}		