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
*	You got a dream, you gotta protect it.
*/ 

#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair
#define pi 2 * acos(0);
#define eps 1e-6
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
int t,n,k,x,y,c,st,d;
string s;
vector<vector<pair<int , int > > > v;
map<string , int > m;
int dist[10005];
bool vis[10005];
int dis () {
	mem(dist,0) ; 
	mem(vis, 0 ) ; 
	rep(i,n) dist[i]=oo;
	priority_queue < pair < int , int > > q ; 
	dist[st]=0;
	vis[st]=0; 
	q.push(mp(0,st) ) ; 
	int r = oo;
	while(!q.empty()) {
		int fr=q.top().second;
		int cc= -q.top().first;
		q.pop();
		if ( fr == d && cc < r  ) 
			return cc;
		if (vis[fr])
			continue;
		vis[fr]=1;
		rep(i,sz(v[fr])) {
			if ( dist[v[fr][i].first ] > cc + v[fr][i].second  && !vis[v[fr][i].first]) {
				dist[v[fr][i].first] = cc+v[fr][i].second;
				q.push(mp( -dist[v[fr][i].first], v[fr][i].first ) ) ;
			}
		}
	}
}
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	scanf("%d",&t) ; 
	while(t--){
		v.clear();
		m.clear();
		scanf("%d",&n) ; 
		v.resize(n);
		rep(i,n) {
			cin>>s;
			m[s]=i;
			scanf("%d",&k);
			rep(j,k) {
				scanf("%d%d",&x,&c) ; 
				v[i].pb(mp(x-1,c));
			//	v[x-1].pb(mp(i,c));

			}
		}
		scanf("%d",&k);
		rep(i,k){
			cin>> s ;
			st = m[s];
			cin>>s ; 
			d = m[s];
			//cout << st << " " << d << endl;
			printf("%d\n", dis());
		}
	}
	return 0 ;
}