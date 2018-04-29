#include<string>
#include<iostream>
#include<stdio.h> 
#include<vector>
using namespace std ;
int main () {
	//freopen("test.in","rt",stdin);
	string s ; 
	vector<string > ss ; 
	int c = 0 ; 

	for ( int i = 0 ; i < 8 ; i++) {
		cin >> s ; 
		ss.push_back(s);
		if ( s[0] == 'B' && s[1] == 'B'  && s[2] == 'B' && s[3] == 'B' && s[4] == 'B' && s[5] == 'B' &&  s[6] == 'B' && s[7] == 'B' ) 
			c++;
	}
	if ( c != 8 ) {
		for ( int i = 0 ; i < 8 ; i++) {
			if ( ss[0][i] == 'B' && ss[1][i] == 'B'  && ss[2][i] == 'B' && ss[3][i] == 'B' && ss[4][i] == 'B' && ss[5][i] == 'B' &&  
				ss[6][i] == 'B' && ss[7][i] == 'B' )
				c++ ; 
		}
	}
	cout << c << "\n";
	return 0 ; 
}