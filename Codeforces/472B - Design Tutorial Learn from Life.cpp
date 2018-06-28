#include <iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
 int  v[2222] ; 
int main() {
	freopen("test.in", "rt", stdin ) ; 
	int n , k , a , c ; 
	scanf("%d%d",&n,&k ) ; 
	c= n ;
	while(n--) {
		scanf("%d",&a); 
		v[a]++; 
	}
	int cur =  1 ; 
	long long res = 0  ;
	for ( int i = 0 ;i <= 2000 ;i++ ) {
		if ( v[i] != 0 ) {
			a = c / k + (  c %k == 0 ? 0 : 1 ) ; 
			res+= ( a * ( i - cur ) ) ; 
			a-- ; 
			res+= ( a * ( i - cur ) ) ; 
			cur = i ; 
			c-=v[i] ; 
		}
	}
	cout << res + ( cur - 1 )  << endl;
	return 0;
}