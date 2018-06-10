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
string s ; 
int n,k;
int dp[500005][30];
inline int calc (int pre , int ind ) {
	if ( ind == n ) 
		return 0 ; 
	int x = s[ind] -'A';
	int res=oo;
	if (dp[ind][pre]!=-1)
		return dp[ind][pre];
	if ( pre != x ) 
		res = min ( res ,calc (x, ind+1));

	for (int i = 0 ; i <k ; i++) 
		if(pre != i ) 
			res = min (res, calc ( i , ind+1)+1);

	return dp[ind][pre]=res;
}
inline void path (int pre , int ind ) {
	if ( ind == n ) 
		return ; 
	int x = s[ind] -'A';
	int res=oo,r1=oo;
	if ( pre != x ) 
		r1 = calc (x, ind+1);
	int r=oo,y;
	for (int i = 0 ; i <k ; i++) 
		if(pre != i ) {
			res= calc ( i , ind+1)+1;
			if ( res < r ) {
				r=res;
				y=i;
			}
		}

		if ( min (r , r1 ) == r1) {
			printf("%c",s[ind]);
			path (x , ind+1);
			return;
		}
		else {
			printf("%c",'A'+y);
			path (y , ind+1);
			return;
		}
}
int  main()
{	
	//freopen("test.in" , "rt" , stdin);
	scanf("%d%d",&n,&k);
	mem(dp,-1);
	cin>>s;
	printf("%d\n" ,calc(29,0));
	path(29,0);
	printf("\n");
	return 0 ;
}