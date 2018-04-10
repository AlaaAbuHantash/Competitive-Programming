#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std ; 
int t ,n ; 
int dp[1008];
vector<vector<int > > v ; 
int calc ( int x ) {
	if ( x == 0 ) 
		return 0 ; 
	if ( x == 1 ) return 1 ; 
	if ( dp[x] != -1 ) 
		return dp[x] ;
	return dp[x] = (calc ( x -1 ) %1000 + calc (x-2) %1000 ) %1000; 
}
int main () {
	scanf("%d",&t) ; 
	memset(dp,-1,sizeof(dp));
	dp[0]=0 ;
	dp[1]=1;
	v.clear() ;
	v.resize(1002);
	calc (1005);
	for ( int i = 0 ; i <= 1000 ;i++) 
		v[dp[i]].push_back(i);

	while(t--) {
		scanf("%d",&n); 
		if(v[n].size()) {
			printf("The last three digits of ");
			for (int i = 0 ; i < v[n].size() -1 ; i++) 
				printf("F(%d), ",v[n][i] ) ; 

			printf("F(%d) are [%d]\n",v[n][v[n].size() -1],n ) ; 

		}
		else 
			printf("These digits seem to be invalid\n");
	}
	return 0 ;
}