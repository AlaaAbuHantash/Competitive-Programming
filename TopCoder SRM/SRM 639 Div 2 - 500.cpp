#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std ; 

class AliceGameEasy  {
public : 
	long long findMinimumValue(long long x, long long y) {

		long long  s = x + y ; 
		long long res ; 
		long long int ind = -1 ;
		if(  x == 0 && y == 0 ) return 0 ;
		for ( long long int i =  1 ; i< 3000000; i++) {
			res = i * (i+1) / 2 ; 
			if ( res == s ) {
				ind = i ;
				break;
			}
		}
		if ( ind == -1 ) return -1 ; 
		long long c = 0 ; 
		for ( long long int i = ind  ; i >= 1 ; i--) {
			if ( x == 0 ) break; 
			if ( x >= i ) {
				x=x-i ; 
				c++;
			}
		}
		if ( x == 0 ) 
			return c ; 
		return -1 ; 
	}


};

int main () {

	//freopen ( "test.in","rt"  , stdin ) ; 
	AliceGameEasy a ; 
	cout << a.findMinimumValue(0 , 1)  ;
	return 0 ; 
}