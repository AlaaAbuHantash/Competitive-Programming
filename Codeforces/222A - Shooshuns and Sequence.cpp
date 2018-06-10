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
	int k , n , x ;
	cin >> n >> k ; 

	vector<int > a(n) ; 

	cin >> a[0] ;
	bool f = true;
	x=0;
	for(int i=1 ; i < n ; i ++ ) 
	{
		cin >> a[i] ;
		if ( a[i-1] != a[i] ) 
		{
			if ( i>=k)
				f = false;
			else 
				x = i;

		}
	}

	if (f) cout << x << endl;
	else cout << -1 << endl;
	return 0;
}

