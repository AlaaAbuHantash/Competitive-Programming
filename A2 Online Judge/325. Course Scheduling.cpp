#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std ; 
int t ,n ,x , m;
int main () {
	scanf("%d",&t) ; 
	int c = 1 ; 
	while(t--){
		scanf("%d%d",&n , &m) ; 
		int sum = 0 ; 
		n = n / 2 + (n%2 == 0 ? 0 : 1 ) ;  
		while(m--) {
			scanf("%d",&x ) ; 
			if ( x >= n ) 
				sum++;
		}
	
	printf("Case %d: %d\n" , c++,sum);
}
return 0 ;
}