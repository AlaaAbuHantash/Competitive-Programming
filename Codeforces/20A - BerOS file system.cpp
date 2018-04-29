#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<string>
#include<map>
using namespace std; 
string s ; 
int main () {

	//freopen("test.in","rt",stdin);
	cin >> s ; 
	bool f = 0 ; 
	string tmp="";
	for ( int i = 0 ; i < s.length() ; i ++) {
		if ( s[i] == '/'  && !f ) {
			f = 1 ; 
			tmp+=s[i] ; 
		}
		else if ( s[i] != '/')  {
			f = 0 ; 
			tmp+=s[i]; 
		}

	}
	int z =tmp.length()-1 ; 
	if ( tmp[z] =='/'  &&z != 0 ) 
		tmp.erase(z,1);
	cout << tmp << "\n" ; 
	return  0;
}
