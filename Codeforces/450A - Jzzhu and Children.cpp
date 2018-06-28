#include<iostream > 
#include<vector> 
#include<queue> 
using namespace std ; 
int main () {
	int res = 0;
	int n , m , x ; 
	cin >> n >> m  ; 
	queue<pair < int , int >  >q;
	for ( int i = 0 ; i < n ; i++) {
		cin >> x ; 
		q.push(make_pair(i,x ) )  ; 

	}
	while(!q.empty() ) {
		if ( q.size() == 1 ) {
			res = q.front().first;
			break;	
		}
		int xx = q.front().second ; 
		xx = xx  - m ; 
		if ( xx > 0 ) 
			q.push(make_pair(q.front().first , xx ) ) ; 
		q.pop();

	}
	cout << res +1<< endl;
}