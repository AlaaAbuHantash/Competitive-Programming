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
int main()
{
	//freopen("test.in" , "rt" , stdin);
	int t  , x  , c  , l;
	map<char , int >  m ; 
	map<char , int >  m2; 
	char ch ;
	string a , b ; 
	cin >> t ;
	 while ( t-- ) 
	 {
		 cin >> a >> b ;
		 for ( int i = 0 ; i < a.length() ; i ++ ) 
			 m[a[i]]++;
		 for ( int i = 0 ; i < b.length() ; i ++ ) 
			 m2[b[i]]++;

		 l = a.length() + b.length() ;
		 c=0;
		 for ( int i = 0 ; i < 26 ; i ++ ) 
		 {
			 ch = 'a' + i ; 
			 if ( m[ch] > m2[ch] )
			    x = m[ch] - m2[ch] ; 
			 else 
				x = m2[ch] - m[ch] ; 
			 c = c + x ;
		 }
		 cout << c << endl;

		 m.clear() ; 
		 m2.clear();
	 }
	return 0;
}
