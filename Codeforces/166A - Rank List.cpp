#include<iostream>
#include<stdio.h> 
#include<algorithm> 
#include<vector> 
#include<string>
#include<math.h>
using namespace std;
int n ,  a,b ,x;
vector<pair<int , int >  > v ;
int main()
{
	scanf("%d%d",&n ,&x) ; 
	for ( int i = 0 ; i < n ; i++) {
		scanf("%d%d",&a,&b) ; 
		v.push_back(make_pair(a,-b));
	}
	int res =0;
	sort(v.rbegin() , v.rend());
	for ( int i = 0 ; i < v.size() ; i++) {
		if ( v[x-1].first == v[i].first && v[x-1].second == v[i].second) 
			res++;
	}
	printf("%d\n",res);
	return 0; 
}