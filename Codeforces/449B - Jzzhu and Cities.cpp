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
*   You got a dream, you gotta protect it.
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
long long  dist[100005];
int a,b,m,n,k,res;
long long c ;
bool vis[100005] ; 
vector<vector<pair <int  , long long  > > > v;
priority_queue<pair<long long , pair <int , bool >  > > q ; 
void calc (){
	mem(vis,0);
	q.push(mp(0,mp(0,0)));
	dist[0]=0;
	//vis[0]=1;
	while(!q.empty()){
		long long cc = -q.top().first;
		bool bb = q.top().second.second;
		int fr = q.top().second.first;
		q.pop();

		if ( bb == 1  && ( dist[fr] <= cc ) ) {
			res++;
			continue;
		}
		else if ( bb==1)
			dist[fr] =cc;
		if (vis[fr]) continue;
		vis[fr]=1;
		rep(i,sz(v[fr])) {
			if (dist[v[fr][i].first] > v[fr][i].second + cc) {
				dist[v[fr][i].first] = v[fr][i].second + cc ;
				q.push(mp(-dist[v[fr][i].first]  , mp(v[fr][i].first,0)));
			}

		}
	}

}
int  main()
{
	 //freopen("test.in" , "rt" , stdin);
	scanf("%d%d%d",&n,&m,&k ) ;
	v.resize(n);
	rep(i,n)
		dist[i]=oo*2;
	rep(i,m){
		scanf("%d%d%I64d",&a,&b,&c);
		a--;b--;
		v[a].pb(mp(b,c));
		v[b].pb(mp(a,c));
	}
	res=0;
	rep(i,k) {
		scanf("%d%I64d",&a,&c);
		a--;
		q.push(mp(-c,mp(a,1)));
	}
	calc();
	printf("%d\n",res);
	return 0 ;
}