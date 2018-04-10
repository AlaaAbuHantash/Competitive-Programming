#include<iostream> 
#include<stdio.h> 
using namespace std ; 
int main () {
	int t ; 
	scanf("%d",&t) ; 
	while(t--) { 
	double s , n , k  , m  , a , b ; 
	cin >> s >> n >> k>> m ;
	 a = n / s ; 
	 b = m / k ; 
	 if ( a >=b ) 
		 printf("%.5f\n",a-b) ; 
	 else 
		 printf("-1\n") ; 
	}
	return 0 ;
}