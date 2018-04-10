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
#include <sstream>
using namespace std;

int main()
{
	//freopen("test.in" , "rt" , stdin);
	int t  , n , r  , i , x;
	cin >> t; 	
	string s ;
	getline (cin , s ) ;
	vector<int>st ;
	while (t-- ) 
	{

		st.resize(155);
		getline(cin,s);
		istringstream a(s);
		i=0;
		while (a >>st[i] )
				++i;

	
		n=i;
		r=0;
		for (  i = 0 ; i < n ; i++)
		{
			//cout << st[i] << endl;

			if ( i == 1 ) 
				r = r - st[i] ; 
			else 
				r = r + st[i]  ;
		}

		cout << r << endl;
		st.clear();
		
	}
	return 0;
}
