#include<iostream > 
#include<stdio.h>

using namespace std ;
	int rr[105];

int main () {
	int x ,a , b , c = 0  ,r  =  0 ; 
	scanf("%d%d",&x,&a) ; 

	while(x--){
		scanf("%d",&b) ;
		for ( int i = a ; i <=b ; i++) {
				c = b / i ; 
				rr[i]+=c;
				r = max ( r , rr[i] * i )  ;
		}

	}
	printf("%d\n",r);
	return 0 ; 
}