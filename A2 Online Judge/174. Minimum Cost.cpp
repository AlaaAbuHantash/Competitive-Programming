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
 
string s1 , s2 ; 
int dp[1001][1001];
int calc ( int x , int y ){

	if ( x == sz(s1) && y== sz(s2 ) ) 
		return 0 ; 
	if ( x >sz(s1) || y>sz(s2 ) ) 
		return oo ;
	if ( dp [x][y] !=-1 ) 
		return dp[x][y] ;
	int res = oo;
	if ( s1[x] == s2[y] ) 
		res = calc ( x+1 , y+1 ) ; 

	int r1 = calc ( x+1 , y )  + 15 ; 
	int r2 = calc ( x , y+1 ) + 30 ; 
	return dp[x][y] = min ( res ,min (r1 , r2 )) ;
}
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	while(cin >> s1 ) {
		mem(dp,-1);
		if ( s1=="#" ) 
			break;
		cin >> s2 ; 
		int res = calc (0,0) ; 
		if ( res == oo ) 
			res = sz(s1 ) * 15 + sz(s2) *30;
		printf("%d\n", res);
	}
	return 0 ;
}