#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std ; 
int t ,n ,x;
int main () {
	scanf("%d",&t) ; 
	int c = 1 ; 
	while(t--){
		scanf("%d",&n) ; 
		int sum = 0 ; 
		while(n--) {
			scanf("%d",&x);
			sum+=x;
		}
		printf("Case %d: %d\n" , c++,sum);
	}
	return 0 ;
}