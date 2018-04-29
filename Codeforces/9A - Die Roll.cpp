#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std; 
int main () {
	int x , y  ; 
	scanf("%d%d",&x,&y) ; 

	x = max ( x , y ) ; 
	if ( x ==  1 ) {
		printf("%d/%d\n" , 1 , 1 );
		return 0 ; 
	}
	int a = 7 - x  ;

	if ( a% 2 == 0 ) 
		printf("%d/3\n" ,  a / 2 );
	else if ( a% 3 == 0 ) 
		printf("%d/2\n" ,  a / 3 );
	else 
		printf("%d/%d\n" , a , 6 );

	return  0;
}