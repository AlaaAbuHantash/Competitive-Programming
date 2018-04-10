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
int t  ,n , m  , x; 
vector<string>s;
string a ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string b ="abcdefghijklmnopqrstuvwxyz" ;
int main()
{
	//freopen("test.in" , "rt" , stdin);
	cin >>t ; 
	while (t--) 
	{
		cin >> n >> m; 
		s.clear();
		s.resize(n);
		for ( int i = 0 ; i < n ; i ++) {
			cin >> s[i] ;
			for ( int j = 0 ; j<s[i].length() ; j++) {
				if ( isupper(s[i][j] ) ) {
					x = s[i][j] - 65 ; 
					x = x + m ; 
					s[i][j] = b[x%26] ;
				}
				else {
					x = s[i][j] - 97 ; 
					x = x + m ; 
					s[i][j] = a[x%26] ;
				}
			}
		}

		cout << s[0] ;
		for ( int i = 1 ; i < n ; i ++) 
			cout << " " <<s[i];
		cout << endl;
	}
    return 0;
}