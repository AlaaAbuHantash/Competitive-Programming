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
int main()
{
	//freopen("test.in" , "rt" , stdin);
	int x , n  , a , b , r1 ,r2  , r , l ; 
	cin >> n  >> x ;
	r1 = 0 ; 
	r2 = 10000;
	while (n--) 
	{
		cin >> a >> b ; 
		r = max ( a, b ) ; 
		l = min ( a , b ) ; 

		r1 = max ( l , r1 ) ; 
		r2 = min ( r , r2 ) ; 
	}

	//cout << r1 << " " << r2 << endl;
	a= min ( abs ( x- r1 )  ,abs ( x -r2 ) ) ; 
	if ( r1 > r2 ) 
		cout << -1 << endl;
	else if ( x >=r1 && x <= r2 )
		cout << 0 << endl; 
	else 
		cout << a << endl;

	return 0;
}