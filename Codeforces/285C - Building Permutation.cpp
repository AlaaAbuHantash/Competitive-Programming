#include<iostream> 
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ; 
int main () {
	int a,n;
	vector<int > v ; 
	scanf("%d",&n);
	for ( int i = 0 ; i < n ; i++ ) {
		scanf("%d",&a);
		v.push_back(a);
	}
	long long int c = 0 ;
	sort(v.begin() , v.end()) ; 
	for ( int i =  0 ; i < n ; i++) 
		c+=(abs ( v[i] - i -1 )  );
	printf("%I64d\n",c);

		return 0;
}