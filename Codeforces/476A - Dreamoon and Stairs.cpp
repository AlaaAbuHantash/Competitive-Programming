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
/* You got a dream, you gotta protect it.*/ 
using namespace std;
int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ; 
int n, m ; 
int dp[10005][15]; 
int calc( int x , int y ) {
	if ( x == n && y== 0 ) 
		return 0 ;
	if ( x >=n ) 
		return 1e9;
	if ( dp[x][y]!=-1) 
		return dp[x][y] ; 

	int r = calc ( x+1 , (y+1) % m )  + 1  ; 
	int rr = calc ( x+2  ,  ( y + 1 ) % m ) + 1  ;  
	return dp[x][y] = min ( r , rr ) ; 
}
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	scanf("%d%d",&n,&m) ; 
	memset ( dp , -1 , sizeof dp ) ;
	int res = calc ( 0 , 0 )  ; 
	if (res >=1e9)
	printf("%d\n" ,-1 );
	else
	printf("%d\n" ,res );
	return 0 ;
}
