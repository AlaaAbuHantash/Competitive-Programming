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

#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair

using namespace std;
int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ; 

int n , m  , t  , b , c , x , minV ,nub , obj ; 
vector<vector<int> > vis;
vector<vector<int> > adj ;
vector<int > v ;
void dfs ( int a , int b , int val ) 
{
	if (vis[a][b])
		return  ;

	vis[a][b] = 1 ;
	nub++;
	//cout << nub << endl;
	for ( int i = 0 ;i < 4 ; i++) {
		int nx =a + dx[i] ; 
		int ny =b + dy[i] ;
		if ( nx >= 0 && ny >= 0 && nx < n && ny < m ) 
			if (adj[nx][ny] == val && !vis[nx][ny])
				dfs(nx , ny , val ) ;

	}

}

int main()
{

	//freopen("test.in" , "rt" , stdin);

	cin >> t ;
	while (t-- ) 
	{
		obj = 0;
		cin >> n >> m;
		adj.clear();
		adj.resize( n , vector<int > (m) ) ;
		vis.clear();
		vis.resize( n, vector<int > (m ) ) ;
		for ( int i = 0 ; i < n; i++) 
			for (int j = 0 ; j < m ; j++) 
				cin >> adj[i][j];

		cin >> c ; 
		v.clear();
		v.resize(c);

		for (int i= 0 ; i < c ; i++) 
			cin >> v[i] ; 


		cin >> b ; 
		pair < int , int > res ; 
		for ( int i = 0 ; i < n ; i++) 
			for (int j = 0 ; j < m ; j++) {
				//minV = oo;
				res = mp(oo,oo);
				for ( int k = 0 ; k < c ;k++) {
					x = abs (adj[i][j] - v[k] ) ; 
					if ( x < res.first || x == res.first && v[k] < res.second ) {
						
						res = mp(x,v[k]);
						//minV = x ; 
					}
				}
				adj[i][j]  = res.second;
			}
				     
		for ( int i = 0 ; i < n; i++) 
			for (int j = 0 ; j < m; j++) { 
				if ( !vis[i][j] ) {
					nub = 0 ; 
					dfs(i,j , adj[i][j]);
					if ( nub >= b ) 
						obj++;
				}
			}


			cout << obj << endl;
	}

	
	return 0 ;
}