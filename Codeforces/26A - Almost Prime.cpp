#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<string>
#include<queue>
#include<map>
using namespace std; 
bool p[3333];
int main () {
	memset ( p , true , sizeof(p));
	p[0]=p[1] = 0 ; 
	for ( int i = 2  ; i*i <3333 ; i++) {
		if ( p[i] ) {
			for ( int j = i*i ; j < 3333 ; j+=i) 
				p[j] = 0 ; 
		}
	}
	int x  , c , res = 0 ; 
	cin >> x ; 
	for ( int i = 2 ; i <= x  ; i ++)  {
		c=0;
		for ( int j = 2 ; j< i ; j++) {
			if ( i %j == 0 && p[j] ) {
				c++; 
			}
			if (c > 2 ) break; 
		}
		if (c == 2 ) res++;
	}

	cout << res<<"\n";
	return  0;
}
