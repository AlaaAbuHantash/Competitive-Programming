#include <iostream>
#include <algorithm>
#include<vector>
#include<stdio.h>
using namespace std;

int main() {
	int n ; 
	cin >> n ; 
	if ( n%2 == 0){
		puts("-1");
		return 0; 
	}
	vector<int > v , vv ; 
	for ( int i = 0 ; i < n ; i++ ){
		v.push_back(i);
		printf("%d ",i );
	}
	puts(""); 
	for ( int i = 1 ; i < n ;i++){
		printf("%d ",i);
			vv.push_back(i );
	}
	vv.push_back(0);
	puts("0"); 
	for ( int i = 0 ; i < n ; i++)
	printf("%d ",(v[i]+vv[i])%n );
	puts("");
	return 0;
}