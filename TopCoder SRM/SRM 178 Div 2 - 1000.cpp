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
class BadSubstring {
public : 

long long n,z,dp[50][5];
long long howMany(int length){
	n=length;
	long long r = 1 ;
	for (int i = 0 ; i <n ; i++ ){ 
		mem(dp,-1);
		z=i;
		r =  calc ( 0 , 1 ) + calc ( 0 , 2 ) + calc ( 0 , 3 ) ; 
	}
	return r ;
}
long long calc ( int x , int y ) {
	if (x ==z ) 
		return 1; 
	if ( dp[x][y] != -1 ) 
		return dp[x][y] ; 
	long long res = 0 ;
	if(y==1 ) 
		res +=calc (x+1 , 1 )  + calc ( x+1, 3 ) ;
	else 
		res +=calc (x+1 , 1 )  + calc (x+1 , 2 ) + calc ( x+1, 3 ) ;

	return dp[x][y]=res ;
}
};
int  main()
{
	//freopen("test.in" , "rt" , stdin);

	return 0 ;
}