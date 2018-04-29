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
using namespace std;
int main()
{
	
 freopen("test.in" , "rt" , stdin);

	int n , m ; 
	cin >> n >> m ; 
	vector<string> s (n);
	for (int i = 0 ; i < n ; i++ )
		cin >> s[i] ;
	int t = n, l = m , r = 0  , b  =  0 ; 
	for ( int i = 0 ; i < n ; i ++ ) 
	{
		for ( int j = 0 ; j < m ; j++) 
		{
			if ( s[i][j] == '*' ) 
			{
			//	cout << t << l << r << b << endl;
				t = min ( i , t ) ; 
				l = min ( j , l ) ;
				r = max ( r , j ) ;
				b = max ( b , i ) ;
			}
		}
	}

	//cout << t << l << r << b << endl;

   for ( int i = t ; i <= b ; i ++ ) 
	{
		for ( int j = l ; j <= r ; j++) 
		{
			cout << s[i][j];
		}
 
		cout << endl;
   }
	return 0;
}
