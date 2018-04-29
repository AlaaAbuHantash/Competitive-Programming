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
#include <cmath>
#include <stdio.h>
#include <string.h>

#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
 
#define oo ((int) 1e9)
#define mp make_pair

using namespace std;
int main()
{
	//freopen("test.in" , "rt" , stdin);
	string s  , a , temp1 , temp2; 
	int t , x ,y ; 
	cin >> s  >> t ;
	map < string , int >  m ; 
	map < string , int >  ::iterator it  ; 


	getline(cin , a ) ;
	while(t--) {
		getline(cin , a ) ;
		x= a.find(' ') ; 
		temp1 = a.substr( 0 ,  x ) ; 
		if (a[x+1] == 'p' ) {

			
			y = a.find('\'');
			temp2=a.substr(x+11 , y - x-11 );

			    m[temp2]+=0;
				m[temp1]+=0;
			if ( temp1 == s || temp2 == s ) {
				m[temp2]+=15;
				m[temp1]+=15;
			}
		}
		else if ( a[x+1] == 'c' ) {
			y = a.find('\'');
			temp2=a.substr(x+14 , y - x-14 );
		
			    m[temp2]+=0;
				m[temp1]+=0;
			if ( temp1 == s || temp2 == s ) {
				m[temp2]+=10;
				m[temp1]+=10;
			}
			
		}
		else if ( a[x+1] == 'l' ) {
			y = a.find('\'');
			temp2=a.substr(x+7 , y - x-7);

			    m[temp2]+=0;
				m[temp1]+=0;
			if ( temp1 == s || temp2 == s ) {
				m[temp2]+=5;
				m[temp1]+=5;
			}
			
		}

	}
	vector<pair<int,string> > p ;

	for ( it = m.begin() ; it!=m.end() ; it++ ) 
		if ( it->first != s ) {
			p.push_back(mp(-1 * m[it->first] , it->first ) ) ;
			//cout << -1 * m[it->first] << " " << it->first <<endl;
		}
		//sort(p.rbegin() , p.rend() ) ; 
		sort(p.begin() , p.end() ) ; 

		rep(i,sz(p))
			cout<<p[i].second <<endl;
	return 0;
}