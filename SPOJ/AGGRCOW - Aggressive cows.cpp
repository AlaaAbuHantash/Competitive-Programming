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
#include <cmath>
#include <stdio.h>
#include <string.h>
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair

using namespace std;
int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ;
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	int t , n ,c , r , nubc , cur ; 
	int l , h  , mid;
	bool f ;
	vector<int > s ;
	cin >>t ; 
	while ( t-- )
	{
		cin >> n >> c ; 
		s.clear();
		s.resize(n);
		rep(i,n)
			cin >> s[i];
	

	sort(s.begin() , s.end() ) ;
	l = 0 ; h = s[n-1] ; 
	while ( l <= h ) 
	{
		mid = (l + h )/2 ;
		cur = 0 ;
		nubc = 1 ; 
	    f= false;
		for ( int i = 1 ; i < n ; i++) 
		{
			//cout << i << "  " << cur << "  " << mid << endl;
			if ( s[i] - s[cur ] >= mid  ) {
				cur = i ;
				nubc++;
			}
		}
		//cout << nubc <<endl;

		if ( nubc >= c ) 
		{
			l = mid +1;
			r = mid ;
		}
		else 
		{
			h = mid -1 ;
		}
	}
	cout << r <<endl;

	}
	return 0 ;
}

