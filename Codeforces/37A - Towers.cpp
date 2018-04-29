#include<iostream> 
#include<stdio.h>

using namespace std;
int arr[1005] , a , b ; 
int  main()
{ 
	//freopen("test.in","rt" ,stdin); 
	int res  = 0 , c = 0 ; 
	scanf("%d",&a);
	for(int i =  0 ; i < a ; i++) {
		cin >> b ; 
		if ( arr [b] == 0 ) 
			c++; 
		arr[b]++;
		res = max ( res ,  arr[b] ); 
	}
	printf("%d %d\n", res , c ) ; 
	return 0 ;
}