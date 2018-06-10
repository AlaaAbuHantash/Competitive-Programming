#include<iostream> 
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ; 
int main () {

	int x , y , a ,c ,res ; 
	scanf("%d%d",&x,&y) ; 
	c= x ; 
	vector<int > v ; 
	while (x-- ) {
		scanf("%d",&a ) ; 
		v.push_back(a) ; 
	}
	sort(v.begin() ,v.end());
	if ( c>=y ) 
		printf("0 %d\n", v[c-y] );
	else 
		printf("-1\n");
	return 0;
}