#include<iostream>
#include<stdio.h> 
#include<string>
#include<map>
using namespace std ; 
int main () {
		//freopen("test.in","rt",stdin);
	string s ; 
	int res=0,n=0;
	map < string ,bool > m ; 
	while ( getline(cin ,s )  && s.size()) {
		if ( s[0] == '+' ) {
			s.erase(0,1);
			m[s] = 1; 
			n++;
		}
		else if ( s[0] =='-'){
			s.erase(0,1);
			n--;
		}
		else {
			int x = s.find(':') ; 

			res+= ( s.size() - x -1) * n ; 
		}

	}
	cout << res<<"\n";
	return 0 ; 
}