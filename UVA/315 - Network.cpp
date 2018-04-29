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

/*
You got a dream, you gotta protect it.
*/ 

#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair

using namespace std;

int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ; 

int geti(){
	int y = 0, s = 1;
	char c = getchar();
	while ( !isdigit(c) && c!='-' ) c = getchar();
	if ( c == '-' ) s = -1 , c = getchar();
	while ( isdigit(c) ) y = y * 10 + ( c - '0' ) , c = getchar();
	return s * y;
}
int t,x,n,c,b;
string s ; 
vector<int >v ,par,low,dis;
vector<vector<int > > adj;
vector<bool>vis;
vector<bool>ap;

void dfs (int x , int time ) {
	vis[x]=1;
	dis[x]=low[x]=time;
	int children = 0;
	rep(i,sz(adj[x]))
		if(!vis[adj[x][i]]){
			children++;
			par[adj[x][i]]= x;
			dfs(adj[x][i] , time+1);
			low[x]  = min(low[x], low[adj[x][i]]);

			// u is an articulation point in following cases

			// (1) u is root of DFS tree and has two or more chilren.
			if (par[x] == -1 && children > 1)
				ap[x] = true;

			// (2) If u is not root and low value of one of its child is more
			// than discovery value of u.
			if (par[x] != -1 && low[adj[x][i]] >= dis[x])
				ap[x] = true;

		}
		else if (adj[x][i] != par[x])
			low[x]  = min(low[x], dis[adj[x][i]]);
}


int  main()
{
	//freopen("test.in" , "rt" , stdin);
	while(scanf("%d",&n)>0){
		if(!n)break;
		getline(cin,s);
		adj.clear();adj.resize(n);
		vis.clear();vis.resize(n);
		low.clear();low.resize(n);
		dis.clear();dis.resize(n);
		ap.clear();ap.resize(n);
		par.clear();par.resize(n,-1);

		while(getline(cin,s)) {
			if (s=="0")break;
			istringstream a(s);
			v.clear();
			while (a >>b) v.pb(b);
			rep(i,sz(v)-1) {
				adj[v[0]-1].pb(v[i+1]-1);
				adj[v[i+1]-1].pb(v[0]-1);
			}

		}
		c=0;
		rep(i,n) {
			if(!vis[i]){
				dfs(i ,1);
				vis.clear();vis.resize(n);
				par.clear();par.resize(n,-1);
				low.clear();low.resize(n);
				dis.clear();dis.resize(n);
			}
		}

		rep(i,n)
			if(ap[i])c++;
		printf("%d\n",c);
	}
	return 0 ;
}