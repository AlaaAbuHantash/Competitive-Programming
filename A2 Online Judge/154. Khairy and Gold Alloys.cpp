#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <utility> 
#include <stack>
#include <cstring> 
#include <math.h>
#include<cstdio>
#include<deque>
#include<sstream>

#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair

using namespace std;
int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ; 
int t ,n ;
long long int r,x ; 
int main() {

	//freopen("test.in" , "rt" , stdin);
	scanf("%d" , &t ) ;
	while (t--) {
		scanf("%d" , &n) ;
		vector<long long int > a (n);
		r=0;
		rep(i,n){
			scanf("%lld" , &a[i]) ;
		}
		long long int pre = 0; 
		rep(i,n-1 ) {
			x= (min(a[i] , a[i+1 ])) ; 

			if ( x > pre ) {
				r+=(x*2) ; 
				r-=pre;
			}
			else {
				r+=(x);
			}

			pre = x ; 
		}

		//if (n==1 ) 
		//	r=a[0];
		printf("%lld\n",r ) ; 

	}
	return 0;
}

