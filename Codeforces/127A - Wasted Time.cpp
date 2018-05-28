#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>
#include<math.h>
using namespace std ; 
#define mp make_pair
vector<pair<int , int > > v ; 
int main () {
	//freopen ( "input.in","rt"  , stdin ) ;
	int n , k , x , y; 
	scanf("%d%d",&n,&k ) ; 
	for (int i = 0 ; i < n ; i++) {
		scanf("%d%d",&x,&y);
		v.push_back(mp(x,y));
	}
	double res = 0 ; 
	for ( int i = 1 ; i < n ; i ++ ) {
		x= v[i].first;
		y=v[i].second;
		int xx = v[i-1].first; 
		int yy = v[i-1].second;
		res+= sqrt(((xx -x ) *( xx -x )) +( (yy-y) * (yy-y)) ) ;
	}
	res = res * k ; 
	double t  = res / 50;
	printf("%.9f\n" ,t ) ;
	return 0 ; 
}