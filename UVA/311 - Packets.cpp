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
/*YOU got a DREAM, YOU gotta protect it. */ 
using namespace std;
int a[6]; 
int  main()
{
	//freopen("input.in","rt",stdin);
	long long res  ;
	int r ; 
	while(scanf("%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5]) >0 ) {
		if ( !a[0] &&!a[1] &&!a[2] &&!a[3] &&!a[4] &&!a[5] )
			break;
		res = 0 ;
		res +=a[5] ; 
		if ( a[4] != 0 ) {
			res +=a[4] ; 
			a[0] = a[0] - min ( a[0] , 11 * a[4] ) ;
		}
		if ( a[3] != 0 ) {
			res +=a[3]; 
			r=  min ( a[1] , 5*a[3] )   ; 
			a[1] = a[1] -  r ;
			r = (4 * 5 * a[3] ) - (r * 4) ; 
			a[0] = a[0] - min ( a[0] , r ) ;
		}
		if ( a[2] !=0 ) {
			r = a[2] % 4  ; 
			res+= (a[2] / 4 ); 
			if ( r != 0 ) 
				res++;

			if ( r == 1 ){
				r = min ( a[1] , 5) ;
				a[1] = a[1] - r ; 
				r = 36 - 9 - ( r * 4 )  ;
				a[0] = a[0] - min ( a[0] , r );
			} 
			else if ( r == 2 ) {
				r = min ( a[1] , 3 ) ;
				a[1] = a[1] - r ; 
				r = (18) - (  4 * r ) ; 
				a[0] = a[0] - min ( r , a[0] ) ;
			}
			else if ( r == 3 )  {
				r = min ( a[1] , 1 ) ; 
				a[1] = a[1] - r ; 
				if ( r == 1 ) 
					a[0] = a[0] - min ( 5 , a[0] ) ; 
				else 
					a[0] = a[0] - min ( a[0] , 9 ) ;
			}
		}

		if ( a[1] !=0 ) {
			r = a[1] % 9 ; 
			res+= a[1] / 9 ; 
			if ( r != 0  ) res ++;
			r = 36 - ( 4 * r ) ; 
			a[0]-= min ( a[0 ] , r ) ;
		}
		if ( a[0] != 0 ) {
			res+=a[0] / 36 ; 
			r = a[0] % 36 ; 
			if ( r !=0 ) 
				res++;
		}
		cout << res <<"\n";
	}
	return 0 ;
}