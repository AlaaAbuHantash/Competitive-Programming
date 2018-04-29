#include<iostream>
#include<stdio.h> 
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std ; 
int vis[105] ; 
int main () {
	//freopen("test.in","rt",stdin);
	long long res = 0 , lst , d  , n , x ;
	cin >> n >>d ; 
	cin >> lst ; 
	n--; 
	while(n-- ) {
		cin >> x ; 
		if ( x <= lst ) {
			long long  z = lst -x ;
			z = z / d ; 
			res+=(z+1) ; 

			lst = x + ( d * ( z+1 ) ) ; 
		}
		else 
			lst = x ; 
	}
	cout <<res << endl;
	return 0 ; 
}