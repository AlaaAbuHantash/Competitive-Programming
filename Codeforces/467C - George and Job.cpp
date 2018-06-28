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

/*  You got a dream, you gotta protect it.*/ 

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

int n,m,k,x; 
vector<int > v;
vector<long long  > p;
long long dp[5005][5005];
long long calc ( int ind , int mm ) {
	if ( ind >= sz(p) && mm == k ) {
		return 0 ; 
	}
	if ( ind >= sz(p) || mm > k )return long long (- 1e13);
	if (dp[ind][mm]!=-1)return dp[ind][mm] ; 
	long long s = - 1e13 ;
	s = max( s ,  calc ( ind +m , mm+1 )+ p[ind] ) ; 
	s = max ( s , calc ( ind + 1 , mm) );

	return dp[ind][mm] = s;
}
int  main()
{
//	freopen("test.in" , "rt" , stdin);
	scanf("%d%d%d",&n,&m,&k ) ;
	rep(i,n){
		scanf("%d",&x ) ;
		v.pb(x);
	}
	mem(dp,-1) ; 
	long long sum;
	rep(i,sz(v)-m+1 ) {
		sum=0;
		rep(j,m) 
			sum+=v[i+j];
		p.push_back(sum) ; 
	}
	cout << calc( 0 , 0  )  << endl;
	return 0 ;
}