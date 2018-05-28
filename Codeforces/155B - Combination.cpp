#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std; 
int main () {
	int n , a,  b ; 
	vector<pair<int , int > > v ; 
	scanf("%d",&n);
	while(n-- ) {
		scanf("%d%d",&a,&b);
		v.push_back(make_pair(b,a));
	}
	sort(v.rbegin() , v.rend()) ;

	int k =  1,res = 0 ;
	for ( int i =  0 ; i < v.size()  && k != 0 ;i++) {
		k-- ; 
		k+=v[i].first ; 
		res+=v[i].second ; 
	}
	printf("%d\n",res);
	return  0;
}