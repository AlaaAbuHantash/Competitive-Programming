#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<string>
#include<map>
using namespace std; 
int n ;
int gcd ( int a , int  b ) {
	if (a%b==0 ) return b ; 
	return gcd(b, a%b);
}
int main () {
	//freopen("test.in","rt",stdin);
	cin >> n ; 
	int sum = 0 , x   , r ;
	for ( int i = 2 ; i < n ; i++) {
		x = i ; 
		r = n ; 
		while ( r!= 0 ) {
			sum+=(r%i ) ; 
			r = r / i ;
		}
		
	}
	printf("%d/%d\n" , sum /gcd(sum , n-2 ), (n-2) / gcd(sum , n-2 ) ) ; 
	return  0;
}
