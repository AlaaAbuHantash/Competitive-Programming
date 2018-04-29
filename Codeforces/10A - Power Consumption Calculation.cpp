#include<string>
#include<iostream>
#include<stdio.h> 
#include<algorithm>
using namespace std ;
int main () {

	//freopen("test.in","rt",stdin);
	int n, a ,b , c  , x,  y ,aa,bb,pre = 0 , sum = 0 , r= 0 ; 
	cin >> n >> a >> b >> c >> x >> y ; 
	for ( int i= 0 ; i < n ; i++) {
		cin >> aa >> bb ; 
		if ( i ==0 ) {
			sum+=( bb - aa  ) * a ; 
			pre = bb ; 
		}
		else {
			sum+=( bb - aa  ) * a ; 
			r = aa - pre ;
			if ( r > x ) {
				r-=x;
				sum+= x  * a ; 
				if ( r > y ) {
					r-=y ; 
					sum+= y* b + (r * c )  ;
				}
				else 
					sum+=r  * b;
			}
			else 
				sum+=( r * a ) ; 

			pre = bb ; 
		}
	}

	cout << sum << "\n";
	return 0 ; 
}