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
	int n  , x = 2 , c = 2 , z; 
	cin >> n ; 
	z = n -1 ;
	while (z-- ) {
		cout << x  << " " ;
		x = (x + c )% n ; 
		if ( x == 0 ) 
			x = n ;
		 c++;
	}
	cout << endl;
	return 0;
}