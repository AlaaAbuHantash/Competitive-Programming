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
int n,t,x,y,z,k;
int v[2005][2005];
int path[2005];
bool vis[2005];
int bfs (){
	queue<pair<int ,int > > q;
	q.push(mp(0,oo));
	mem(vis,0);
	mem(path,0);
	path[0]=-1;
	vis[0]=1;
	while(!q.empty()){
		int fr = q.front().first;
		int c = q.front().second;
		q.pop();
		vis[fr]=1;
		if(fr==n-1)
			return c;
		for(int i=0;i<n;i++) {
			if(v[fr][i] >0 && !vis[i] ) {
				path[i]=fr;
				vis[i]=1;
				q.push(mp(i,min(v[fr][i] , c)));
			}
		}
	}
	return 0;
}
void maxflow (){
	int flow=0;
	while(true){
		int r=bfs();
		if(!r)break;
		flow+=r;
		int pre = n-1;	
		while(pre !=-1 && pre != 0  ){
		//	cout << pre << " " << path[pre ] << endl;
			v[path[pre]][pre]-=r;
			v[pre][path[pre]]+=r;
			pre=path[pre];
		}
	}
	printf("%d\n",flow);
}
int  main()
{
	//freopen("test.in" , "rt" , stdin);

	scanf("%d",&t) ; 
	while(t--) {
		scanf("%d",&n) ; 
		mem(v,0);

		rep(i,n-1) {
			scanf("%d",&k ) ;
			rep(j,k){
				scanf("%d",&x);
				if (i==0 || x == n ) 
					z=1;
				else 
					z=	oo;
				v[i][x-1]=z;
			//	v[x-1][i]=z;
			}
		}
		maxflow();
	}
	return 0 ;
}
