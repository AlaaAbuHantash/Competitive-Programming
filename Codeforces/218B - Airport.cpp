#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>
#include<math.h>
using namespace std ; 
#define mp make_pair

int main () {
//	freopen ( "input.in","rt"  , stdin ) ;
	int n ,m , x ; 
	vector<int > v ; 
	scanf("%d%d",&n,&m) ;
	priority_queue<int > q ; 
	for ( int i = 0 ; i < m ; i ++) {
		scanf("%d",&x); 
		v.push_back(x);
		q.push(x);
	}

	int r = 0 , nn = n , res = 0  ; 
	while (nn>0 && !q.empty() ) {
		r= q.top();
		res+=r ; 
		q.pop() ; 
		if ( r- 1 >= 0 ) 
			q.push(r-1 ) ; 
		nn--;
	}
	nn = n ; r = 0 ; 
	int mres = 0 ; 
	sort(v.begin() , v.end()) ; 
	while ( nn > 0 ) {
		for ( int i = v[r] ; i >0 && nn ; i-- ) {
			mres+=i;
			nn--;
		}
		r++;
	}
	printf("%d %d\n" , res , mres ) ; 
	return 0 ; 
}