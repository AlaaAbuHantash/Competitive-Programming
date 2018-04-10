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
int t , n , c ;
vector <int> a ; 
vector <int> b ; 

int main()
{
	//freopen("test.in" , "rt" , stdin);
	cin >>t ; 
	while (t--) {
		cin >> n ; 
		c=0;
		a.resize(n) ;
		b.resize(n) ;

		for ( int i = 0 ; i < n ; i ++ ) {
			cin >> a[i] ; 
			b[i] = a[i] ;
		}

		sort(a.begin() , a.end() ) ; 

		for ( int i = 0 ; i < n ; i++) 
			if( a[i] == b[i] ) 
				c++;

		cout << c << endl;
	}
    return 0;
}