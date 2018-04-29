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
#include<sstream>
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair

using namespace std;
int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ;
int n , a  ; 
int dp[50][50];
vector<int > nub , com;
int LCS (int i , int j )
{
	if ( i == n || j == n ) 
		return 0 ;

	if (dp[i][j] != -1 ) 
		return dp[i][j] ; 

	if ( com[i] == nub[j] ) 
		return dp[i][j] = LCS( i+1 , j+1 ) +1 ; 

	return dp[i][j] = max ( LCS( i , j+1 ) , LCS( i+1 , j )) ;
}
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	cin >> n ; 
	nub.resize(n);
	com.resize(n);

	rep( i , n ) 
	{
		cin >> a ;
		nub[a-1] = i ;
	}
	while ( cin >> a ) {
		com[a] = 0 ;
		for(int i = 1 ; i < n ; i++) {
			cin >> a ; 
			com[a-1] = i  ; 
		}
		memset(dp , -1 , sizeof (dp) ) ;
		cout << LCS(0,0) <<endl;
		com.clear() ;
		com.resize(n);
	}
	
	return 0 ;
}

