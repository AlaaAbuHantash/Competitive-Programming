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
#include<bitset>
/*
* You got a dream, you gotta protect it.
*/ 

#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair
#define pi 2 * acos(0);
#define eps 1e-9
using namespace std;
int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ; 

int geti() {
	int y = 0, s = 1;
	char c = getchar();
	while ( !isdigit(c) && c!='-' ) c = getchar();
	if ( c == '-' ) s = -1 , c = getchar();
	while ( isdigit(c) ) y = y * 10 + ( c - '0' ) , c = getchar();
	return s * y;
}
int t,n,x,c;
string fr,r;
//bool vis[1001][1001];
bitset<1001>vis[1001];
vector<pair <pair<int ,int > , pair <int , int > > > q ;
void path (int x){
	if(x==-1)
		return ;
	path(q[x].first.first);
	putchar(char('0'+q[x].first.second));
}
int bfs () {
	rep(i,9){
		q.pb(mp (mp(-1, i+1), mp((i+1)%n,i+1)));
		vis[(i+1)%n][i+1]=1;
	}
	int p=0,i;
	while( p<sz(q)) {
		int siz = sz(q);
		for (i = p ; i < siz ; i++ ) {
			int mod = q[i].second.first;
			int sum = q[i].second.second;
			rep(j,10) {
				int nmod =( mod * 10 + j)%n ,nsum=sum+j;
				if (!vis[nmod][nsum]   && nsum<=n ){
					vis[nmod][nsum]=1;
					q.pb(mp(mp(i,j),mp(nmod,nsum)));
					if (nsum == n && nmod ==0 ){
						path(sz(q)-1);
						return 0;
					}
				}
			} p=i;
		}
	}
}
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if (n<10){
			printf("%d\n",n);
			continue;
		}
		q.clear();
		bfs();
		mem(vis,0);
		putchar('\n');
	}
	return 0 ;
}