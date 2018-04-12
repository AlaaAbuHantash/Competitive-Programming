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
class ForbiddenStrings {
public:
	long long dp[31][4][4];
	int len ; 
	long long countNotForbidden(int n){
		mem(dp,-1) ; 
		len=n;
		return calc(0,0,0);
	}
	long long calc ( int x  , int pre1 , int pre2) {
		if ( x == len ) 
			return 1 ;
		if (dp[x][pre1][pre2] != -1 ) 
			return dp[x][pre1][pre2];
		long long res=0;
		if (( pre1==1 && pre2 == 2 ) ||(( pre1==2 && pre2 == 1 )))
			res+=calc(x+1 , pre2 , 1 ) + calc(x+1 , pre2 , 2) ;
		else if (( pre1==1 && pre2 == 3 ) ||(( pre1==3 && pre2 == 1 ) ))
			res+=calc(x+1 , pre2 , 1 ) + calc(x+1 , pre2 , 3) ;
		else if (( pre1==3 && pre2 == 2   )|| ( pre1==2 && pre2 == 3 ) ) 
			res+=calc(x+1 , pre2 , 3 ) + calc(x+1 , pre2 , 2) ;
		else 
			res+=calc(x+1 , pre2 , 1 ) + calc(x+1 , pre2 , 2)+calc(x+1 , pre2 , 3 ) ;

		return dp[x][pre1][pre2]=res ;
	}
};
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	return 0 ;
}