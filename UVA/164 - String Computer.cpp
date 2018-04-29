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
//Da01Cg03If04E
int dp[105][105];
string a,b;
int calc ( int i , int j ) {
	if ( i==sz(a) && j == sz(b) ) 
		return 0 ; 
	if ( i > sz(a) || j>sz(b) ) 
		return oo;
	if(dp[i][j]!=-1)
		return dp[i][j];
	if ( a[i] == b[j] ) 
		return dp[i][j] = calc ( i+1, j+1) ; 
	return dp[i][j] = min (calc(i+1,j+1)+1, min(calc( i+1 , j ) +1  , calc(i,j+1) +1 ));
}
void path(int i, int j , int len ) {
	if ( i==sz(a) && j == sz(b) ) {
		printf("E\n");
		return ;
	}
	if ( a[i] == b[j] )  {
		path(i+1,j+1,len+1);
		return ;
	}
	int r1 = calc(i+1,j+1)+1 ,r2 = calc(i+1,j)+1 , r3 =calc(i,j+1)+1; 
	int r = min ( r1 , min ( r2 , r3 )) ; 
	if ( r == r1 ) {
		printf("C%c",b[j] ) ; 
		if ( len > 9 ) 
			printf("%d",len);
		else 
			printf("0%d",len);
		path (i+1,j+1 , len+1);
		return ;
	}
	else if ( r == r2 ) {
		printf("D%c",a[i] );
		if(len > 9 ) 
			printf("%d",len ) ;
		else 
			printf("0%d",len);
		path (i+1, j , len );
		return ;
	}
	else {
		printf("I%c",b[j] ) ;
		if ( len > 9 ) 
			printf("%d",len) ; 
		else 
			printf("0%d",len) ; 
		path(i,j+1,len+1);
		return ;
	}
}
int  main()
{	
	//freopen("test.in" , "rt" , stdin);
	while(cin>>a ) {
		if (a=="#")break;
		cin>>b;
		mem(dp,-1);
		path(0,0,1);
	}
	return 0 ;
}
