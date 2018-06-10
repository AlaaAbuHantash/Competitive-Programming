#include<iostream> 
#include<stdio.h>
#include<algorithm>
using namespace std ; 
int arr[200];
int  main()
{ 
	//	freopen("test.in","rt" ,stdin); 
	for ( int i = 2 ; i < 400 ;i++) {
		if ( (180* (i-2 )  )% i == 0 ) 
			arr[ ( i-2) *  180 /  i ] = 1 ;
	}

	int n  ,t ;
	scanf("%d",&t) ; 
	while(t--){
		scanf("%d",&n) ; 
		if (arr[n] ) 
			printf("YES\n");
		else 
			printf("NO\n");
	}
	return 0 ;
}