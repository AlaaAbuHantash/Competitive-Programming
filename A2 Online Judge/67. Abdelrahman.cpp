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
int  main()
{

	//freopen("test.in" , "rt" , stdin);
	int t  , n , m , a = 1 , r ; 
	cin >> t ; 
	while ( t-- ) 
	{
		cin >> n >> m ; 
		n-- ; 
		r = m - n ; 
		cout << "Case " << a++ << ": " << r << endl;
	}
	return 0 ;
}

