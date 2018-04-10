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

vector<int> nub;
bool dp (int sum  , int x ) 
{
	if ( sum == 0 ) 
		return true;

	if ( x == 0 && sum != 0 ) 
		return false;

	if (nub[x-1] > sum)
		return dp(sum  , x-1);

	return dp(sum, x -1) || dp( sum-nub[x-1] , x-1);
}
int  main()
{

	//freopen("test.in" , "rt" , stdin);
	int t  , n ,  k ;
	cin >> t ; 
	while ( t-- ) 
	{
		cin >> n >> k ; 
		nub.clear() ; 
		nub.resize(k) ;

		rep(i,k)
			cin >> nub[i];

		bool f = dp(n , k ) ;

		if ( f && n ) 
			cout << "YES" <<endl;
		else 
			cout << "NO" <<endl;

	}
	return 0 ;
}

