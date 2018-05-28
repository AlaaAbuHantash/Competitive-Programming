#include<iostream>
#include<stdio.h> 
#include<string>
#include<vector> 
using namespace std ; 
int main () {
	//freopen("test.in","rt",stdin);
	int n ; 
	string s  ,res = ""; 
	bool f = 0 ; 
	vector<string> v ;
	cin >> n ; 
	while ( n-- ) {
		cin >> s ; 
		if ( s == "pwd") {
			cout <<"/";
			for ( int i = 0 ; i < v.size() ; i++)
				cout << v[i] << "/" ; 
			cout << endl;
		}
		else {
			cin >> s  ; 
			if ( s[s.size() -1 ] == '/' ) {
				v.clear();
				continue;
			}
			f= 0 ;
			for ( int i = 0 ; i < s.size(); i++) {
				if ( s[i] =='.' ) {
					if (v.size())
						v.pop_back() ; 	
					i++;
					res = "" ;
				}
				else if ( s[i] != '/' ) {
					res+=s[i]; 
				}
				else if ( s[i] == '/' && f  ) {
					if ( res.length() ) 
						v.push_back(res);
					res = "";
				}
				else if ( s[i] == '/' && !f ) {
					v.clear();
				}
				f=1;
			}
			if ( res.length() ) 
				v.push_back(res);
			res = "" ;
		}
	}
	return 0 ; 
}