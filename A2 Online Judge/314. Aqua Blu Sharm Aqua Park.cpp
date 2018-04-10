#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h> 
using namespace std ; 
int t , n , c  ; 
int v[16][16] , a[16] ; 
int dp[1<<14][105][15] , vis[1<<14][105][15] ; 
int id ; 
int calc ( int cc , int ind , int msk  ) {
//	cout << cc << " " << ind << " " << nub << endl;
	int r =  0  ; 
	if ( vis[msk][cc][ind]  == id ) 
		return dp[msk][cc][ind] ; 
	 vis[msk][cc][ind]  = id ; 
	for ( int i = 1 ; i < n ; i++) 
		if ( ( ( msk >> (i -1 )  ) & 1 ) != 1 ) {
			if ( cc - a[i] - v[ind][i] >= 0 ) 
				r = max ( r , calc ( cc - a[i] - v[ind][i] , i , msk | ( 1 << (i -1 ) )  ) +1 ) ; 
			//else if ( cc - v[ind][i]>= 0 ) 
			//	r = max ( r , calc ( cc - v[ind][i] , i  , msk | ( 1 <<(i -1 )  )  )  ) ; 
		}
		return  dp[msk][cc][ind] = r; 
}
int main () {
	int ca = 1;
	//freopen("test.in" ,"rt", stdin);
	memset(vis, 0 , sizeof ( vis  )  ) ;
	scanf("%d",&t ) ; 
	id = 0 ; 
		a[0] = 0 ;
	while ( t-- ) {
		scanf("%d%d",&n,&c ) ; 
		id++;
		for ( int i =  1 ; i <n  ; i++) {
			scanf("%d",&a[i]  ) ;
		}
		for ( int i = 0 ; i < n ; i++) 
			for ( int j = 0 ; j <n ; j++) 
				scanf("%d",&v[i][j] );	
		int res = calc ( c ,  0  , 0 ) ; 
		printf("Case %d: %d\n", ca++ , res);
	}
	return 0 ; 
}