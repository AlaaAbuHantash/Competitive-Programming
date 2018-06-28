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
int t,x,n,k , y,a,b;
int nn,id;
long long  dp[100005];
long long  vis[100005];
long long  r[100005];
vector<pair<int , int  > > v;
long long calc( int a ) {

	if ( a == 0) 
		return 1 ; 
	if ( a<0 ) 
		return  0 ; 
	if(dp[a] != -1 )
		return dp[a];

	long long r = 0 ; 
	r=calc(a-1)%1000000007  + calc(a-k)%1000000007 ;
	return dp[a]=r%1000000007;
}
int  main()	
{
	//freopen("test.in" , "rt" , stdin);
	scanf("%d%d",&t,&k);

	mem(dp,-1);
	int a = 0 ; 
	int b = oo;
	long long res = 0  ; 
	while(t--){
		scanf("%d%d",&x,&y);
		a=max( a , max ( x , y )) ;
		b=min(b , min ( x , y )) ;
		v.pb(mp(x,y));

	}
	r[0] = 0 ;
	for(int i = 1 ; i <= a ; i++) {
		res=calc(i);
		r[i]=r[i-1] + res;
	}

	rep(i,sz(v)) {
		res =( r[v[i].second] -r[v[i].first-1] )	 ; 
		cout << res%1000000007 << "\n";
	}
	return 0 ;
}
