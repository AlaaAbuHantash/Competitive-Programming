#include<iostream>
#include<stdio.h> 
#include<vector>
#include<algorithm>
using namespace std; 
int main () {
	vector<int > a (3); 
 
	scanf("%d%d%d",&a[0],&a[1],&a[2] ) ; 
	int res = max ( max ( a[0] + a[1 ] + a[2] ,a[0] * a[1] *a[2]  ) , max ( a[0] *( a[1] + a[2])  , (a[0] + a[1]) * a[2] 	) ) ; 
	res = max ( res , max ( a[0] *a[1] + a[2], a[0] + a[1]* a[2]  ) ) ;  
	printf("%d\n",res);
	return 0 ;
}