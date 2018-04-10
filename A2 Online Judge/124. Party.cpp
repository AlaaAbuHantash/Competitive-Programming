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
	//freopen("test.in" , "rt" , stdin);

	int t  , d , n ,c , x  , r ;
	cin >> t; 
	while (t-- ) 
	{
		cin >> d >> n  ;
		c=0;
		vector<int>a (n) ;

		for ( int i = 0 ; i < n ; i ++ ) 
				cin >>a[i];
			

		sort (a.rbegin(),a.rend());
		d--;
		for ( int i = 0 ; i < n ; i ++ ) 
		{
			if ( a[i] < d )
			{
				d--;
				c++;
			}
		}

		cout << c << endl;

		a.clear();

	}
	return 0;
}
