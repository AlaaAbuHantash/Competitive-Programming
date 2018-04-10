#include<iostream>
#include<vector>
#include<stdio.h> 
#include<queue> 
#include <string.h>

using namespace std ; 
int main () {

	int x , a , b , c , n , m ; 
	cin >> x ; 
	int d = 1, res ;
	int vis[1005], dist[1005];
	int pr[10005];
	pr[1]=0;
	for ( int i =2 ; i < 10005 ;i++) {
		int g = 0 ;
		for ( int j = 2 ; j < i ; j++) {
			if ( i% j == 0 ) {
				g=1;
				break;
			}
		}
		if ( g == 0 ) 
			pr[i] = 1 ; 
	}
	while(x--){
		cin >> n >> m ; 
		vector<vector <pair < int , int > > > v ( n +1  ) ; 
		memset(vis,0,sizeof(vis));
		while(m--) {
			cin >> a >> b >> c ; 
			v[a].push_back(make_pair(b, c) ) ; 
			v[b].push_back(make_pair(a, c) ) ; 
		}
		cin >> a >> b ;
		priority_queue<pair<int , int  > > q ; 
		q.push(make_pair(0 , a ) ) ;
		dist[a] = 0 ; 
		vis[a] = 1 ; 
		for ( int i =  1 ; i <= n+1 ; i++) 
			dist[i] = 2e9 ;
		bool f = 0 ;
		while(!q.empty()) {
			int fr = -q.top().first; 
			int xx = q.top().second; 
			q.pop();
			if ( xx == b ) {
				res = fr;
				f =1 ; break;
			}
			vis[xx] =1 ; 
			for ( int i = 0 ; i < v[xx].size() ; i++) 
				if ( !vis[v[xx][i].first] && fr + v[xx][i].second < dist[v[xx][i].first] && pr[v[xx][i].second] == 1  ) {
					dist[v[xx][i].first] = fr + v[xx][i].second; 
					q.push(make_pair ( -dist[v[xx][i].first] , v[xx][i].first) ) ;
				}
		}
		if (f ) 
			printf("Case %d: %d\n",d++,res ) ; 
		else 
			printf("Case %d: -1\n",d++);
	}
	return 0 ; 
}