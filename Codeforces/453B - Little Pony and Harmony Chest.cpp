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
int n,x, a[105] , p[22] ={1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53, 59,61,67,71,73},res;
int pp[60];
int dp[1<<17][101] ; 
int yy ; 
int calc (int mask , int x ) {
	if ( x == n ) return 0 ; 
	if ( dp[mask][x] != -1 ) return dp[mask][x] ; 
	int res = oo ;
	res = min ( res , calc ( mask | ( 1<<0 ) , x+1 ) + abs(a[x] - p[0] ) ) ;
	bool f=false;
	for ( int i = 2 ; i <=55 ; i ++ ) {
		f=false;
		if (( mask & pp[i] )== 0 ) {
			res= min (res , calc (mask | pp[i] ,x+1) + abs ( a[x] - i ) ) ;
		}
		//for ( int  j = 1 ; j <17 ; j ++ ) {
		//	//cout <<   ( ( ( mask >> j ) & 1 ) == 1 )  << "  pr " <<  ( ( (pp[a[x]] >> j ) & 1 ) == 1 )  << " " << a[x] << endl;
		//	if ( ( ( ( mask >> j ) & 1 ) == 1 ) && ( ( (pp[i] >> j ) & 1 ) == 1 )  ) {
		//		f=true;break;
		//	}
		//}
		//if(!f) 
		//	res= min (res , calc (mask | pp[i] ,x+1) + abs ( a[x] - i ) ) ;
	}
	return dp[mask][x] = res;
}
void path (int mask , int x ) {
	if (x==n)return ;
	int res =  calc ( mask | ( 1<<0 ) , x+1 ) + abs(a[x] - p[0] ) ;
	int nub = 1, msk = (1<<0) ; 
	bool f;
	for ( int i = 2 ; i <=55; i ++ ) {
		f=false;
		for ( int  j = 1 ; j <17; j ++ ) {
			if ( ( ( ( mask >> j ) & 1 ) == 1 ) && ( ( (pp[i] >> j ) & 1 ) == 1 )  ) {
				f=true;break;
			}
		}
		if(!f) {
			int r = calc (mask | pp[i] ,x+1) + abs ( a[x] - i )  ;
			if ( r < res ) {
				res = r ; 
				nub = i ;
				msk =  pp[i];
			}
		}
	}

	printf("%d ",nub ) ; 
	path (mask|msk,x+1);
	return ;

}
void pre () {
	mem(pp,0);
	for (int i = 1 ; i <= 55 ; i++) {
		int tmsk = 0 ; 
		for ( int j = 1 ; j <17; j++ ) {
			if (i % p[j] ==0 ) {
				tmsk = tmsk | (1<<j) ;
			}
		}
		pp[i]=tmsk;
	}
}
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	scanf("%d",&n) ;
	rep(i,n ) 
		scanf("%d",&a[i] ) ; 


	mem(dp,-1);
	pre();
	//cout << calc (0,0) << endl;
	calc(0,0) ;
	path(0,0);
	printf("\n");
	return 0 ;
}