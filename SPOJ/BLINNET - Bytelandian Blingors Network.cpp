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

class DisjointSets
{

public:
	vector<int> parent;
	vector<int> rank;	
	int ncomps;
	DisjointSets(int n)
	{
		rank.clear();
		rank.resize(n);
		parent.clear();
		parent.resize(n);
		ncomps = n;
		DisJS(n);
	}
	void DisJS( int n ) 
	{
		for ( int i = 0  ; i < n ; i++)
		{
			parent[i] = i ;
			rank[i]=0;

		}
	}
	int find(int x ) 
	{
		return ((parent[x] == x )? x : parent[x] = find( parent[x] ))  ;
	}

	bool join ( int x , int y ) 
	{
		int px = find(x) ; 
		int py = find(y);

		if ( py != px ) 
		{
			if(rank[py] > rank[px])
				swap ( px , py ) ; 
			parent[py] = px ;
			if ( rank[px] == rank[py] ) rank[px]++;
			 ncomps--;
		}

		return px != py ;
		  
	}
};

struct edge 
{
	int to , from , w ; 
	edge ( int from , int to , int w ): from(from) , to(to) , w(w) {}
	bool operator < ( const edge & e ) const {
		return w > e.w;
	}
};

priority_queue<edge > pq;
int t,n,x,y,c,k;
string s;
map<string , int > m;

void MST()
{
	DisjointSets d(n);
	vector<edge> e ; 

	int cost =0; 

	while( !pq.empty() ) 
	{
		edge temp = pq.top();
		pq.pop();
		if (d.join(temp.from , temp.to) ) 
		{
			cost+= temp.w ; 
			e.pb(temp);
		}
	}

	printf("%d\n",cost);
	
	while( !pq.empty() ) 
		pq.pop();
}

int  main()
{
	//freopen("test.in" , "rt" , stdin);
	scanf("%d",&t) ; 
	while(t--){
		m.clear();
		scanf("%d",&n) ; 
		rep(i,n) {
			cin>>s;
			m[s]=i;
			scanf("%d",&k);
			rep(j,k) {
				scanf("%d%d",&x,&c) ; 
				pq.push(edge(i,x-1,c));

			}
		}
		MST();
	}
	return 0 ;
}