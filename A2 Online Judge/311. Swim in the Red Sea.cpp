#include<iostream> 
#include<vector>
#include<stdio.h>
#include<string.h>
using namespace std; 
int dp[1<<12][12][1005]; 
int n  ,t , x ; 
vector<vector<int > > v ;
int calc ( int msk , int ind , int mm) {
	if ( ind == n ) 
		return mm ; 
	int r = 2e9; 
	if(dp[msk][ind][mm] != -1) 
		return dp[msk][ind][mm] ;
	for ( int i = 0 ; i < n ;i++) {
		if ( ( ( msk >> i  ) &  1 )  != 1  ) {
			r = min  ( r , calc ( msk  | ( 1 << i )  , ind + 1  , max ( mm , v[ind][i] ) ) )  ;
		}
	}
	return dp[msk][ind][mm]= r ; 
}
int main () {
	//freopen("test.in" , "rt" , stdin);
	scanf("%d",&t) ; 
	int c = 1  ;
	while(t-- ) {
		scanf("%d",&n);
		v.clear();
	//	memset(dp, -1 , sizeof(dp));
		v.resize(n);
		for ( int i = 0 ; i < n ; i ++) {
			for(int j = 0 ; j < n ; j++) {
				cin >> x ; 
				v[i].push_back(x);
			}
		}
		for(int i = 0 ; i < (1<<(n+1)) ; i++) 
			for ( int j = 0 ; j < n+1 ; j++  ) 
				for ( int k = 0 ; k < 1002 ;k++) 
				dp[i][j][k]=-1;
		int res = calc ( 0 , 0 , 0 ) ; 
		printf("Case %d: %d\n",c++,res);
	}
	return 0 ; 
}