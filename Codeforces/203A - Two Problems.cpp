#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>
#include<math.h>
using namespace std ; 
#define mp make_pair

int main () {
	//	freopen ( "input.in","rt"  , stdin ) ;
	int x ,  t , a , b ,c ,d   ,sa,sb; 
	bool f = 0 ; 
	scanf("%d%d%d%d%d%d",&x,&t,&a,&b,&c,&d);
	for ( int i = 0 ; i < t &&!f ; i ++) 
		for ( int j = 0 ; j < t &&!f; j ++) {
			sa = a - (i * c ) ; 
			sb = b - ( j*d ) ; 
			if ( sa+sb== x  || sa == x || sb == x	) 
				f = 1 ; 
		}
		if(f||!x)puts("YES");
		else 
			puts("NO");
	return 0 ; 
}