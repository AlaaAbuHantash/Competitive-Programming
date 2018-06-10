#include<iostream>
#include<stdio.h> 
#include<algorithm> 
#include<vector> 
#include<string.h>
#include<math.h>
using namespace std;
bool p[10000005] ; 
int main()
{
	memset(p ,true, sizeof(p)) ; 
	p[0] = 0 ; 
	p[1] = 0 ; 
	for ( int i = 2 ; i*i<=1000000;i++){
		if ( p[i] ) {
			for ( int j = i*i;j<=1000000;j+=i)
				p[j] = 0;	
		} 
	}
	int n  ; 
	long long x  , c; 
	scanf("%d",&n) ; 
	for ( int i = 0 ; i < n ; i++) {
		cin >> x ; 
		c = sqrt( x ) ;
		if ( c*c==x && p[c]  ) 
			puts("YES");
		else 
			puts("NO");

	}
	return 0; 
}