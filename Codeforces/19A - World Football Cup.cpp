#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<string>
#include<queue>
#include<map>
#include<math.h>
#define mp make_pair 
using namespace std; 
int main () {
	//freopen("test.in","rt",stdin);
	int n ,x , y ;
	char c ; 
	cin >> n ; 
	map < string, pair< int , pair < int , int > > > m ; 
	map < string, pair< int , pair < int , int > > >  ::iterator it ;
	string s  ,  a ,b , t , tt ; 
	for ( int i = 0 ; i < n ; i ++) {
		cin >> s ; 
		m[s].first = 0 ; 
	}
	for ( int i= 0; i < n*(n-1 ) / 2 ;i ++ ) {
		cin >> a; 
		x = a.find('-') ; 
		t = a.substr(0,x ) ;
		tt=a.substr(x+1 ) ;
		cin >> x >> c >> y ; 
		m[t].second.second+=x ;
		m[tt].second.second+=y ;
		m[tt].second.first+=( y-x )  ;
		m[t].second.first+=( x- y )  ;
		if ( x == y ) {
			m[t].first++;
			m[tt].first++;
		}
		else if ( x > y ) {
			m[t].first+=3;
		}
		else {
			m[tt].first+=3;
		}
	}
	vector<pair<pair<int , pair < int , int > > ,string > > res ;
	vector<string > rr ;
	for ( it=m.begin() ;it!=m.end() ;it++) {
		res.push_back(mp(mp(m[it->first].first , mp(m[it->first].second.first , m[it->first].second.second ) )  , it->first) ) ;
	}
	sort(res.rbegin() ,res.rend()) ;
	n=n/2;
	for ( int i= 0 ; i < n ; i++) 
		rr.push_back(res[i].second) ; 

	sort(rr.begin() , rr.end());
	for ( int i = 0 ; i < n ; i++) 
		cout<<rr[i]<<"\n";
	return  0;
}
