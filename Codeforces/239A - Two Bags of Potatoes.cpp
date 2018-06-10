#include<iostream>
#include<stdio.h>
using namespace std ; 
int main () {
	bool f = 0 ;
	int y , n , k  ,x = 0 ; 
	scanf("%d%d%d",&y,&k,&n) ; 

	x = y % k  ;

	for ( int i = k- x  ; i+y <= n  && (i+y)/k <=100000 ; i+=k) {
		if ( ( i + y ) % k == 0 ) {
			f = 1 ; 
			printf("%d ",i);
		}
	}

	if ( !f) puts("-1");
	return 0 ; 

}