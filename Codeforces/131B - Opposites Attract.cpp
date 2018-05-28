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

	int n ,x , t; 
	cin >> n; 
	long long c , z ;
	//vector<vector<int > > v ( n  , vector <int> (n ) ); 
	map<int , bool > m ;
	map<int , bool > ::iterator it ;
	map<int , long long  > v ;

	for ( int i = 0 ; i < n ; i++) 
	{
		cin>>t;
		m[t] = 1; 
		v[t]++;
		//cout << t << " " << v[t] << endl; 
	}
	c=0;
	for ( it=m.begin() ; it != m.end() ; it++) {

		x = (it->first )* -1 ; 
		if ( x == 0 ) {
			v[x]--;
			z =  (v[x])*( v[x]+1 ) / 2;
			c = c+z;
			continue;
		}
		if ( m[x]  ) {
			m[x] = 0 ; 
			m[ it->first  ] = 0 ;
			c = c + ( v[x] * v[it->first]) ;
		}
	}

	cout << c << endl;
}