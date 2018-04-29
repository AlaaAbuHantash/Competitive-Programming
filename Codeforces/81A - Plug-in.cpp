#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std ; 
int main () {

	//freopen ( "test.in","rt"  , stdin ) ; 
	string s , tmp="" , res="" , t  ;
	cin >> s ;

	for ( int i = 0 ; i < s.size();i++){
		int x = s.find(s[i] , i+1);

		if ( x >= 1 && x < s.size()){ 
			tmp = s.substr(i,x-i+1); 
			t =tmp;
			if ( tmp.size()%2 == 0 ) {
				reverse(t.begin(),t.end());
				if ( tmp == t ) {
					i=x;
				}
				else if (  !res.empty() && res[res.size()-1 ] == s[i] )
					res.erase(res.size() -1 , 1 ) ; 
				else {
					res+=s[i];
				}
			}
			else if (    !res.empty() && res[res.size()-1 ] == s[i] )
				res.erase(res.size() -1 , 1 ) ; 
			else 
				res +=s[i];

		}
		else if (    !res.empty() && res[res.size()-1 ] == s[i] )
			res.erase(res.size() -1 , 1 ) ; 
		else 
			res+=s[i];
		//cout <<res << " " << s[i] << endl;


	}
	cout <<res << endl;
	return 0 ; 
}