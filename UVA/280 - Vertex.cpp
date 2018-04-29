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
int n,m,a,b,t;
vector<vector<int> > adj;
vector<bool>vis;
vector<int>res;
void dfs(int x) {

	rep(i,sz(adj[x]))
		if(!vis[adj[x][i]]) {
			vis[adj[x][i]]=1;
			dfs(adj[x][i]);
		}
}
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	while(scanf("%d",&n)>0){
		if(!n)break;
		adj.clear();adj.resize(n);
		while ( scanf("%d",&a) >0 ) {
			if(!a)break;
			a--;
			while(scanf("%d",&b)>0) {
				if(!b)break;
				b--;
				adj[a].pb(b);
			}
		}
		scanf("%d",&t);
		while(t--){
			res.clear();
			vis.clear();vis.resize(n);
			scanf("%d",&a);
			a--;
			dfs(a);

			rep(i,n) {
				if(!vis[i]) 
					res.pb(i);
			}

			printf("%d",sz(res));
			if(sz(res) != 0 ){
				printf(" %d",res[0]+1);
				rep(i,sz(res)-1) 
					printf(" %d",res[i+1]+1);
			}
			printf("\n");
		}


	}
	return 0 ;
}