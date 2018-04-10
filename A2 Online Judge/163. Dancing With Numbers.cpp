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
 
struct edge 
{
	int to , from , w ; 
	edge ( int from , int to , int w ): from(from) , to(to) , w(w) {}
	bool operator < ( const edge & e ) const {
		return w > e.w;
	}
};
 
int geti(){
	int y = 0, s = 1;
	char c = getchar();
	while ( !isdigit(c) && c!='-' ) c = getchar();
	if ( c == '-' ) s = -1 , c = getchar();
	while ( isdigit(c) ) y = y * 10 + ( c - '0' ) , c = getchar();
	return s * y;
}
 
int t , n , m , s , e ;
int a , b , w ; 
int dist[115][115] ;
bool vis[115][115];
 
priority_queue<edge> pq ; 
vector<vector <int > > adj;
 
void dijkstra ()
{
	mem(vis,0);
	dist[0][0]= adj[0][0];
	pq.push(edge(0,0,dist[0][0]));
	while (!pq.empty()) 
	{
		int x = pq.top().from , y = pq.top().to , v = pq.top().w;
		vis[x][y] = 1 ;
		pq.pop();
		if ( x == n-1 && y == m-1 ) 
		{
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x +dx[i] , ny = y+dy[i]  ; 
			if ( nx >= 0 && ny >= 0 && nx < n && ny < m )
				if( !vis[nx][ny] ) 
				{
					if ( adj[nx][ny] + v  < dist[nx][ny] ) {
						 dist[nx][ny] = adj[nx][ny] + v ;
						pq.push(edge (nx,ny , dist[nx][ny] ));
 
					}
				}
			}
 
		}
 
	printf("%d\n",dist[n-1][m-1] ) ;
		while (!pq.empty()) 
			pq.pop();
}
 
 
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	t = geti();
	while ( t-- ) 
	{
		n = geti() , m = geti();
		adj.clear() ; 
		adj.resize(n, vector<int > (m) ) ;
		rep ( i , n) 
			rep( j , m ) {
				w = geti();				
				adj[i][j] = w ; 
				dist[i][j]=oo;
		}
		dijkstra ();
	}
	return 0 ;
}