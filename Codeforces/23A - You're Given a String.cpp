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
	map<string , int >  m ;
	int res = 0; 
	cin >> s; 
	string tmp ; 
	for ( int i = 0 ; i <s.length() ; i++) {
		for ( int j = 0; j <s.length()-i; j++) {
			tmp = s.substr(i, j+1) ; 
			m[tmp] ++ ; 
			int x= tmp.length();
			if ( m[tmp]>=2 ) 
				res = max ( res ,  x) ;
		}
	}
	cout << res << "\n" ;
	return  0;
}
