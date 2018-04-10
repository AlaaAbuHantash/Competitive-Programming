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

#define mp make_pair

using namespace std;
int main()
{
	//freopen("test.in" , "rt" , stdin);

	int t  , p , n ,pr , c; 
	cin >> t ; 
	vector<int > r ; 
	vector<int > g ; 
	vector<int > b ; 
	int sum = 0 ;
	char ch ;
	while (t-- ) {
		cin >> p >> n ; 
		r.clear() ; 
		g.clear() ; 
		b.clear() ; 

		for ( int i = 0 ; i < n ; i++) { 
			cin >> ch >> pr ;
			if ( ch == 'R' ) 
				r.push_back(pr) ; 
			else if ( ch == 'G') 
				g.push_back(pr) ; 
			else if ( ch == 'B' ) 
				b.push_back(pr) ;
		}

		sort(r.begin() , r.end() ) ;
		sort(g.begin() , g.end() ) ;
		sort(b.begin() , b.end() ) ;
		sum = 0 ; 
		c=0;
		for ( int i = 0 ; i < r.size() ; i++) {
			sum = sum + r[i] ; 
			if ( sum > p ) 
				break;
			c++;
		}
		cout <<"Red balls = " << c << endl;
		sum = 0 ; c = 0 ; 

		for ( int i = 0 ; i < g.size() ; i++) {
			sum = sum + g[i] ; 
			if ( sum > p ) 
				break;
			c++;
		}
		cout <<"Green balls = " << c << endl;

		sum = 0 ; c = 0 ; 

		for ( int i = 0 ; i < b.size() ; i++) {
			sum = sum + b[i] ; 
			if ( sum > p ) 
				break;
			c++;
		}
		cout <<"Blue balls = " << c << endl;


		if ( t != 0 ) 
			cout << endl;
	}

	return 0;
}
