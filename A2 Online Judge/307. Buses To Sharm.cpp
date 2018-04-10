#include <iostream> 
#include<stdio.h> 
#include<string> 
using namespace std ; 
int main () {
	int x , a , b ;
	cin >> x ; 
	int c = 1 ; 
	string s ="ACM-ACPC-2013" ; 
	while(x-- ) {
		cin >> a >> b ; 
		a =a%13 ; 
		b = b%13 ; 
		printf("Case %d: %c\n", c++ , s[(a+b ) %13] ) ;  
	}
	return 0 ; 
}