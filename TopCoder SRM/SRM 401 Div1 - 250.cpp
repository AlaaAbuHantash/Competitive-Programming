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
class FIELDDiagrams {
public :
	long long dp[31][31];
	int n ; 
	long long countDiagrams(int fieldOrder){
		n=fieldOrder;
		long long  r =0;
		mem(dp,-1);
		for ( int i =1; i <=n ;i++) 
			r+=calc (n, i) ; // 2 1   2 2
		return r;
	}
	long long calc ( int x, int nub) {
		if ( x == 0 ) 
			return 1 ; 
		if ( dp[x][nub] !=-1)
			return dp[x][nub];
		long long res=0;
		for ( int i = 0 ; i <=min(nub,x-1); i++) 
			res+=calc ( x-1 , i);

		return dp[x][nub]=res;
	}
};
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	return 0 ;
}