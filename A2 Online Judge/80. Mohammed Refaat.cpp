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
int t , n , m , s , e ;
int a , b , w ; 
vector<vector< pair < int , int > > > adj;
int dist [100005] ;
void dijkstra ()
{
	dist[s]= 0;
	queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int fr = q.front();
      q.pop();
      for (int i = 0; i < adj[fr].size(); i++) {
          int w = adj[fr][i].second;
          if (dist[fr] + w < dist[ adj[fr][i].first]) {
            dist[adj[fr][i].first] = dist[fr] + w;
            q.push( adj[fr][i].first);
          }
        
      }
    }

}
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	int c= 1;
	scanf("%d",&t);
	while ( t-- ) 
	{

		scanf("%d %d",&n,&m);
		adj.clear() ; 
		adj.resize(n);
		rep ( i , m ) 
		{
			scanf("%d %d %d", &a, &b, &w);
			a--;b--;
			adj[a].push_back(mp(b,w) ) ;
			adj[b].push_back(mp(a,w) ) ;


		}
		scanf("%d %d",&s,&e);
		s--; e--;
		rep(i,n)
			dist[i] = 2e9;
		dijkstra ();
		cout << "Case " << c++ << ": " <<dist[e]<<endl;
	}
	return 0 ;
}

