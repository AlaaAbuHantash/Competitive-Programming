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
using namespace std;
int t ,c;
string s  , r; 
int main()
{
	//freopen("test.in" , "rt" , stdin);
	cin >>t ; 
	while (t--) {
		cin >> s ;
		c=1;
		r = "";
		for ( int i = 1 ; i < s.length() ; i++ ) {
			if ( s[i] != s[i-1] ) {
				cout << s[i-1]  << c ;
				c= 1 ;
			}
			else {
				c++;
			}
		}
		
		cout << s[s.length()-1]  << c<< endl;
	}
    return 0;
}