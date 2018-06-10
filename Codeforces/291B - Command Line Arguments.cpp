#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std ; 
int main () {
	//freopen ( "test.in","rt"  , stdin ) ; 
	string s ,tmp = "", t = ""; 
	int c  =   1 ;
	vector <string > ss ;
	getline(cin,  s  ) ;

	for ( int i = 0 ; i < s.size() ;i++) {

		if (  s[i] == '\"' && !c ) {
			c = 1 ;
			cout << "<"<<tmp << ">\n";
			tmp = "" ;
		}
		else if ( s[i] == '\"' && c ) 
		{
			if (!tmp.empty()) {
				t="";
				ss.clear();
				for ( int j = 0 ; j < tmp.size(); j++) {
					if (tmp[j] != ' ' ) {
						t+=tmp[j];
					}
					else {
						if ( !t.empty() ) 
							ss.push_back(t);
						t="";
					}
				}
				if ( !t.empty() ) 
					ss.push_back(t);

				for ( int k = 0 ; k < ss.size() ; k++)
					cout << "<"<<ss[k]<< ">\n";
			}
			c = 0 ; 
			tmp = "";
		}
		else 
			tmp+=s[i];

	}

	if (!tmp.empty()) {
		t="";
		ss.clear();
		for ( int j = 0 ; j < tmp.size(); j++) {
			if (tmp[j] != ' ' ) {
				t+=tmp[j];
			}
			else {
				if ( !t.empty() ) 
					ss.push_back(t);
				t="";
			}
		}
		if ( !t.empty() ) 
			ss.push_back(t);

		for ( int k = 0 ; k < ss.size() ; k++)
			cout << "<"<<ss[k]<< ">\n";
	}
	return 0 ; 
}