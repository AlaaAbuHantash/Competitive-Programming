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
int n,x,y,z;
vector<pair < pair < int , int > ,int > > a; 
int dp[30*6+2][30*6+2];
int LIS (int c , int p) {
	if ( c == sz(a) ) 
		return  0;
	if(dp[c][p] != -1 ) 
		return dp[c][p];
	int res=LIS(c+1 , p ) ; 
	if (a[p].first.first < a[c].first.first && a[p].first.second< a[c].first.second) 
		res = max ( res , LIS(c+1, c ) + a[c].second);
	return dp[c][p]=res;
}
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	while(scanf("%d",&n)>0) {
		if (!n)break;
		a.clear();
		mem(dp,-1);
		rep(i,n) {
			scanf("%d%d%d",&x,&y,&z);
			a.pb(mp(mp(x,y),z));
			a.pb(mp(mp(y,x),z));
			a.pb(mp(mp(z,y),x));
			a.pb(mp(mp(y,z),x));
			a.pb(mp(mp(z,x),y));
			a.pb(mp(mp(x,z),y));
		}
		sort(a.begin(), a.end());
		int r = 0 ;
		rep( i ,sz(a))
			r = max ( r , LIS(i+1,i )+a[i].second) ;
		printf("%d\n" ,r );
	}
	return 0 ;
}