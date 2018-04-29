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
using namespace std;
#define mp make_pair 
map<string , int > m ; 
map<int , string > mm;
vector<vector< pair < int , int > > > v ; 
int st , e ;
int dist[111];
int vv[111][111];
string ss[111][111];
int path [111]; 
void dijkstra() {
	for ( int i = 0 ; i <=100 ; i++) 
		dist[i] = 2e9;

	priority_queue<pair <int , int > > q ; 
	dist[st] = 0 ; 
	path[st]= -1 ;
	q.push(mp(0,st));
	while(!q.empty() ) {
		int c = -q.top() .first; 
		int nod = q.top().second;

		q.pop(); 
		if ( nod == e )
			break;
		for ( int i = 0 ; i < v[nod].size() ; i++) {
			int nnod = v[nod][i].second;
			int nc = v[nod][i].first;
			if ( dist[nnod] > nc + c ) {
				dist[nnod]  = nc + c ; 
				path[nnod] = nod ;
				q.push(mp (-dist[nnod] , nnod ) );
			}
		}
	}
	vector<int > p ; 
	int x = e; 
	p.push_back(e);
	while ( path[x] != -1 ) {
		p.push_back(x) ; 
		x=path[x] ;
	}
	string tmp = mm[st] ;
	int tt = st; 
	printf("From                 To                   Route      Miles\n");
	printf("-------------------- -------------------- ---------- -----\n");

	for (int i = p.size() -1 ; i > 0 ; i--) {
		printf("%-20s %-20s %-10s %5d\n",tmp.c_str()  , mm[p[i]].c_str() , ss[tt][p[i]].c_str() , dist[p[i]] - dist[tt]) ;
		tmp=mm[p[i]];
		tt=p[i] ; 
	} 
	printf("                                                     -----\n");
	printf("                                          Total      %5d\n", dist[e]);

}
int main () {
	//freopen("test.in","rt",stdin	);
	string s ,a ,b , c , d  ; 
	v.resize(111);
	int  cc =  1 ; 
	for ( int i = 0 ; i <101 ;i++) 
		for ( int j = 0 ; j<101 ;j++) 
			vv[i][j] = 2e9;

	while(getline(cin,s)) {
		if (s.length() == 0 ) 
			break; 
		int x = s.find(',') ;
		a=s.substr(0,x);
		int y = s.find (',',x+1);
		b=s.substr(x+1 ,y-x -1 ) ;
		int z = s.find(',' , y+1 ) ; 
		c=s.substr( y+1,z -y -1) ; ;
		d=s.substr(z+1  ) ;
		if (m[a] == 0 ) m[a] = cc++;
		if (m[b] == 0 ) m[b] = cc++;
		mm[m[a]] = a ; 
		mm[m[b]] = b ;

		int r = atoi(d.c_str());

		if ( vv[m[a]][m[b]] > r || vv[m[b]][m[a]] > r ) {
			vv[m[a]][m[b]] = r ; 
			vv[m[b]][m[a]] = r ; 
			ss[m[a]][m[b]] = c;
			ss[m[b]][m[a]] = c;
		}
		v[m[a]].push_back(mp(r,m[b] ) );
		v[m[b]].push_back(mp(r,m[a] ) );

	}

	bool f = 0 ; 
	while(getline(cin,s)) {
		if (s.length() == 0 ) 
			break; 

		printf("\n\n");

		int x = s.find(',') ;
		a=s.substr(0,x);
		b=s.substr(x+1) ;
		st = m[a] ; 
		e = m[b] ; 
		dijkstra ();
	}

	return 0 ;
}