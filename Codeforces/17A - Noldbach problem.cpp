#include<iostream>
#include<stdio.h> 
#include<string>
#include<map>
using namespace std ; 
bool p[2007];

int main () {
	//freopen("test.in","rt",stdin);
	memset(p,1,sizeof p);
	for(int i=2;i*i<=2005;i++)
		if(p[i])
			for(int j=i*i;j<=2005;j+=i)
				p[j]=false;

	int n , k ; 
	cin >> n >> k ; 
	int lst = 2  , c = 0 ; 
	for ( int i = 3 ; i<= n ; i++) {
		if ( p[i] ) {
			int x = i + 1 + lst  ; 
			if (x > n ) break;
			if ( p[x] ) c++; 
			lst = i;
		}
	}
	if ( c  >= k ) printf("YES\n");
	else printf("NO\n");

	return 0 ; 
}