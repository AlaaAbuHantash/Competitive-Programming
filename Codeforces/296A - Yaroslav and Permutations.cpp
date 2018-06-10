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
int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ;
int m[1111];
int  main()
{
   //freopen("input" , "rt" , stdin);
    //freopen ("myfile.txt","w",stdout);
	int n , a  , s=0 , r = 0 ;
	cin >> n ;
	for (int i = 0 ; i< n ; i++){
		cin >> a ;
		m[a]++;
		r = max ( m[a] , r ) ;
		s++;
	}
	s-=r;
	if ( r-1 <= s)
		puts("YES");
	else
		puts("NO");

    return 0 ;
}

