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
*   You got a dream, you gotta protect it.
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
int x,t;
int dp[20000008];
int calc(int n ) {
	//cout << n << endl;
	if (n == 1 ) 
		return 0 ; 
	if (dp[n]!=-1)
		return dp[n];
	int r1=oo,r2=oo;
	int x1 , x2 ; 
	x1 = n%2 ; 
	x2= n%3 ; 
	r2=calc ((n-x2)/3)+x2+1;
	r1=calc((n-x1)/2)+1+x1;
	return dp[n]=min(r1,r2);
}
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	mem(dp,-1);
	dp[1]=0;
	dp[2]=1;
	dp[3]=1;
	int c=1;
	scanf("%d",&t) ;
	while(t--){
		scanf("%d",&x);
		int res = min ( x , min ( calc ( x ), calc ( x)) );
		printf("Case %d: %d\n",c++,res);
	}
	return 0 ;
}