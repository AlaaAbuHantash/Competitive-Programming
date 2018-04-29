#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<string>
#include<map>
using namespace std; 
int main () {
	//freopen("test.in","rt",stdin);
	string a,  b ,c  , d ; 
	cin >> a >>b >> c ;
	d= b ; 
	reverse(c.begin() , c.end() ) ;
	reverse(d.begin() , d.end() ) ;
	if ( a == c &&  d == b ) 
		printf("YES\n");
	else
		printf("NO\n");
	return  0;
}
