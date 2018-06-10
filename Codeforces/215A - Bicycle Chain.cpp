#include<iostream>
#include<stdio.h> 
#include<algorithm> 
#include<vector> 
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int x , m  ,n , res = 0 ; 
	vector <int > a ,b,r; 
	scanf("%d",&n);
	for ( int i = 0 ; i < n ; i++) {
		scanf("%d",&x);
		a.push_back(x);
	}

	scanf("%d",&m);
	for ( int i = 0 ; i < m ; i++) {
		scanf("%d",&x);
		for ( int j = 0 ; j < n ; j++) {
			if ( x % a[j] == 0 ) {
				if ( x / a[j] > res ) {
					r.clear();
					res = x / a[j]  ; 
					r.push_back(x / a[j] )  ;
				}
				else if ( x / a[j] == res ) 
					r.push_back(x / a[j] )  ;
			}
		}
	}

	printf("%d\n",r.size());
	return 0; 
}