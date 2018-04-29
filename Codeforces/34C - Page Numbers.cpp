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

string s  ,r , temp ; 
int nub ,c; 
set <string > ch ; 
set <string> ::iterator  it ; 
vector<int > n ; 
map<int , string > m ;

int conv ( string s ) {

	int x = 0  , r = 0 ; 
	bool f = false;
	rep ( i , sz(s) ){
		if ( f ) 
			r = r * 10 ; 
		x = s[i] - 48 ; 
		r = r + x ; 
		f= true;
	}
	return r ; 
}
int main()
{
	//freopen("test.in" , "rt" , stdin);

	cin >> s ; 

	temp = "" ; 
	rep ( i , sz(s) ) {
		if ( s[i] == ',') {
			ch.insert(temp) ;
			temp = "" ; 
		}
		else 
			temp+=s[i];
	}

	ch.insert(temp) ;

	for(it = ch.begin() ; it!= ch.end() ; it++ ) {
		nub = conv(*it) ; 
		//cout << nub << endl;
		n.push_back(nub);
		m[nub]= *it;
	}
	sort(n.begin(),n.end());
	c=0;
	r = "" ;
	for ( int i = 1 ; i < sz(n) ; i++) {
		if ( n[i-1]+1 == n[i]) 
		{
			c++;
		}
		else {
		//	cout << c <<endl;
			if ( c== 0 ) 
				r =  r + m[n[i-1]] + "," ; 
			else 
				r = r +m[ (n[i-1] - c ) ]+ "-" + m[(n[i-1] )]+ "," ; 
			

			c=0;
		}
	}

	if ( c== 0 ) 
	    r =  r + m[n[sz(n)-1]] ; 
	else 
		r = r +m[ (n[sz(n)-1] - c ) ]+ "-" + m[(n[sz(n)-1] )] ; 

	cout << r << endl;
	return 0;
}