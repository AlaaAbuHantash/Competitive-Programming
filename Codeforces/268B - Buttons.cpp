#include<iostream> 
#include<stdio.h>
using namespace std ; 
int  main()
{ 
	int n ; 
	//freopen("test.in","rt" ,stdin); 
	scanf("%d",&n) ; 
	int res = n, pre = 0 ; 
	pre = n -2  ; 
	for ( int i = 1 ; i < n -1; i++ ) {
		res+= 1 + ( (i+1 ) *( pre ) )   ; 
		pre-- ; 
	}
	if ( res == 1 ) res = 0 ;
	res++;
	cout << res << "\n";
	return 0 ;
}