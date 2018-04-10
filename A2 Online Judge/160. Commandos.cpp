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
#include <cmath>
#include<cstdio>
#include<deque>
#include<sstream>

#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair

using namespace std;
int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ; 
int t ,l,x,y ,n, res , c ; 
int dp[20][20][20] , a[20][20][20] ; 
int maxsum (int i , int j , int k ) {

	if ( i == 0 || j >= 10 || k>=10 ) 
		return 0 ;

	if ( dp[i][j][k] != -1)
		return dp[i][j][k] ;

	int r1 = 0 , r2 =0 , r3 = 0  ; 

	if( j+1 < 10 ) 
		r1 = maxsum(i , j+1 , k ) ; 
	if ( k+1 < 10 ) 
		r2 = maxsum(i, j, k+1 ) ; 
	if ( i-1 >= 0 )
		r3 = maxsum(i-1 , j , k) ; 

	dp[i][j][k] = max( r1 , max( r2 , r3 ) ) + a[i][j][k] ;

	return dp[i][j][k] ; 

}

int main () {
	//freopen("test.in" , "rt" , stdin);

	scanf("%d",&t) ; 
	while (t-- ) {
		scanf("%d" ,&n);
		mem(dp,-1);
		mem(a,0);
		res = 0 ;
		rep(i,n){
			scanf("%d%d%d%d" ,&l, &x,&y,&c );
			a[l][y][x] = c ;
		}

		res = maxsum(10,1,1) ;
		printf("%d\n", res) ; 

	}

	return 0; 
}