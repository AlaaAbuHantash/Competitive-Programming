#include<iostream>
#include<stdio.h>
using namespace std ; 
int main () {

	int a[10],x,y,z;
	for ( int i = 0 ; i < 9 ; i ++) 
		scanf("%d",&a[i] ) ; 

	for ( int i = 1 ; i <=100000 ; i++) {
		if ( i+a[2]+a[1]  == i + a[3] + a[6]  ) {
			x = i ; 
			y = i + a[1] - a[6] ;  
			z = i + a[1] - a[5] ; 
			if ( y > 0 && z > 0 && i+a[2]+a[1]   == x + y + z  ) {
				a[0] = x ; 
				a[4] = y ; 
				a[8] =  z ; 
				break;
			}
		}
	}

	for ( int i = 0 ; i < 9 ; i ++) 
		printf("%d ",a[i] ) ; 
	return 0 ; 
}