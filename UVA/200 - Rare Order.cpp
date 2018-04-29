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
int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ;
using namespace std;
vector<vector<int> > adj ; 
vector<bool > vis ;
vector<bool > vis1 ;

vector<int > r;
void dfs (int x ) 
{
	vis[x] = 1 ; 
	for ( int i = 0 ; i < sz(adj[x] ) ; i++ ) 
	{
		if ( !vis[adj[x][i]]  ) 
		{
			dfs(adj[x][i]);
		}
	}

	r.push_back(x);

}
int  main()
{
	freopen("test.in" , "rt" , stdin);
	vector<string > s ; 
	string a ; 
	while ( cin >> a ) 
	{
		if ( a =="#" ) 
			break;

		s.push_back(a);
	}

	adj.resize(26);
	vis.resize(26);
	vis1.resize(26);


	for ( int i =1 ; i < sz(s) ; i++ ) 
	{
		for ( int j = 0 ; j < min(sz(s[i]), sz(s[i-1] ) ) ; j++ ) 
		{
			vis1[int(s[i-1][j]-'A')] = 1 ; 
			vis1[int (s[i][j]-'A') ] = 1 ;
			if ( s[i-1][j] != s[i][j] ) 
			{
				adj[int (s[i-1][j]-'A')].push_back(int(s[i][j]-'A'));
				break;
			}

		}
	}


	for ( int i = 0 ; i < 26 ; i++) 
		if ( !vis[i] && vis1[i] ) 
		{
			dfs(i);
		}


		for ( int i = sz(r)-1 ;i >=0 ; i-- ) 
		{
			cout << char(r[i]+'A') ; 
		}

		cout <<endl;
		return 0 ;
}