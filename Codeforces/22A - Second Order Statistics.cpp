#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std ; 
int vis[405];
int main () {

	//freopen ( "test.in","rt"  , stdin ) ; 
	int t ,x ; 
	scanf("%d",&t);
	vector<int > v ;
	for ( int i = 0 ; i < t ; i++) {
		scanf("%d",&x);
		if( x < 0  && !vis[x+205]){
			v.push_back(x);
			vis[x+205] = 1;
		}
		else 	if ( !vis[x] && x>=0 ) {
			v.push_back(x);
			vis[x] = 1;
		}

	}
	sort(v.begin(),v.end());

	if ( v.size() < 2 ) 
		printf("NO\n");
	else 
		printf("%d\n",v[1]);
	return 0 ; 
}