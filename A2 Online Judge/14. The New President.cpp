#include <iostream>
#include<string> 
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<math.h>
#include<string.h>
using namespace std;
#define mp make_pair 
int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ; 

int main() {
	//freopen("input.in","rt",stdin);
	//freopen ("myfile.txt","w",stdout);
	int t , c , n  ,x; 
	int v[111][111] ,  z[111][111];
	scanf("%d",&t) ; 
	while(t--  ) {
		scanf("%d%d",&c,&n);
		memset(v, 0, sizeof(v ) )  ; 
		for ( int i = 0 ; i < n ; i++) {
			for ( int j = 0 ; j < c ; j ++) {
				scanf("%d",&x);
				v[j][x] ++ ;
				z[i][j] = x ; 
			}
		}
		int res = 0 ; 
		int mid = n/2 ;
		vector<int > r ; 
		for ( int i = 1 ; i <=c ; i ++) {
			if ( v[0][i] > mid ) {
				if (v[0][i] > res ) {
					r.clear();
					r.push_back(i);
					res = v[0][i];
				}
				else if ( v[0][i] == res ) {
					r.push_back(i);
				}
			}
		}

		if ( r.size() ==1 ) 
			printf("%d 1\n", r[0]) ;  
		else {
			res = 0 ; 
			vector<pair < int , int > > r2 ; 
			for ( int i = 1 ; i <=c ; i ++) {
				r2.push_back(mp(v[0][i] , i ) )  ; 
			}
			sort(r2.rbegin() , r2.rend());
			int aa = 0 , bb = 0  ;
			for ( int i = 0 ; i < n ; i++) {
				for ( int j =0 ; j< c ; j++)  {
					int xx = z[i][j] ; 
					if ( z[i][j] ==r2[0].second ) {
						aa++ ;break;
					}
					if ( z[i][j] == r2[1].second) {
						bb++;break;
					}

				}
			}
			if ( aa >= bb )
				printf("%d 2\n", r2[0].second) ;  
			else
				printf("%d 2\n", r2[1].second) ;  

		}
	}
	return 0 ; 
}
