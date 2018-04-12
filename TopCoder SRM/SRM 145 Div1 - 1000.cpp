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
long long dp[51][101][3][51];

class HillHike {
public:
	vector<int > a ; 
	int n1,n2;
	long long numPaths(int distance, int maxHeight, vector <int> landmarks) {

		mem(dp,-1);
		n2=distance ; 
		n1=maxHeight;
		a=landmarks;
		return  calc (0,0,0,0);

	}
	long long  calc ( int h , int d , int  f , int curh) {
		if ( h== 0 && d == n2 && f  && curh == sz(a) ) 
			return 1;
		if ( d >=n2 )
			return 0 ;
		if(dp[h][d][f][curh]  !=  -1 ) 
			return dp[h][d][f][curh] ;
		long long res = 0 ;
		int cc = curh;
		if (sz(a) > curh && h == a[curh] ) 
			cc = curh+1;
		// =h +d  
		if ( h != 0 )
			res+= calc (h, d+1,f, cc ) ;
		// +h +d 
		if ( h+1 < n1 ) 
			res+=calc(h+1,d+1,f, cc) ; 
		if(h+1 == n1) 
			res+=calc(h+1,d+1,1, cc);
		// -h +d 
		if ( h-1 > 0 || (h-1 == 0 && d+1==n2)  ) 
			res+=calc (h-1,d+1,f, cc);
		return dp[h][d][f][curh]=res;
	}
};
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	return 0 ;
}