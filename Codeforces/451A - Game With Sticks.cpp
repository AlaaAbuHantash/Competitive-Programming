#include<iostream> 
#include<stdio.h> 
#include<algorithm>
#include<math.h>
using namespace std ; 
int main () {
	int a , b , c ; 
	scanf("%d%d",&a,&b);
	c = min ( a , b ) ; 
	if(c%2==0 ) 
		printf("Malvika\n");
	else 
		printf("Akshat\n"); 
	return 0 ;
}