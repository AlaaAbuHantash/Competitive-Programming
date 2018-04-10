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

#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair

using namespace std;
int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ;
vector <vector<int > > adj;
vector <vector<bool> > vis;
vector<bool> v; 
int re, m , n , t ;
vector<int > res ; 
void dfs (int x , int y ) 
{
	vis[x][y] =1 ; 

	for ( int i = 0 ; i < 8 ; i++) {
		int nx = dx[i] + x  , ny = dy[i] + y ; 
		if ( nx >=0 && ny >=0 && nx < n && ny < m ) 
			if ( adj[nx][ny] == adj[x][y]  && !vis[nx][ny] ) 
				dfs(nx,ny);

	}

	res.push_back(adj[x][y]);
}
int main()
{
	//freopen("test.in" , "rt" , stdin);
	cin >>t ; 
	while (t-- ) 
	{
		cin >> n >> m ;
		re=0;
		adj.clear();
		vis.clear() ; 
		vis.resize(n , vector<bool > (m) );
		v.clear() ; 
		v.resize(205);
		adj.resize(n , vector<int > (m) ) ;
		rep(i,n) 
			rep(j,m)
			cin >> adj[i][j];

		rep(i,n) 
			rep(j,m)
			if ( adj[i][j] != -1 ) {
			if ( !v[adj[i][j]] && !vis[i][j] ) 
			{
				res.clear();
				dfs(i , j ) ; 
				if (sz(res)>=2)
				{
					re++;
					v[adj[i][j]] = 1 ;
				}
			}
			}
			printf("%d\n",re);
	}
	return 0;
}

