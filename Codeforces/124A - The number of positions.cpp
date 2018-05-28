#include <iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
   // freopen("test.in", "rt", stdin ) ; 
	int n , a , b  , res = 0 ; 
	cin >> n >> a >> b ; 
	if ( n - a <  b ) {
		res = n - a ; 
	}
	else 	if ( n- a == b ) { 
		res = b ; 
	}
	else 
		res = b + 1; 
	printf("%d\n", res ); 
    return 0;
}