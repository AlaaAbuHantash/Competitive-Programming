#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility> 
#include <stack>
#include <cstring> 
using namespace std;
	vector <int > a ;

int main()
{
	int n  , i ;
	a.resize(50000 , 0); 
	for(i= 1 ; i < a.size() ; i ++ ) 
		{
			a[i] = a[i-1] + i ; 
			//cout << a[i] << " " << i << endl;
	    }
	
	a[0] = 1 ;
	//cout << a.back() << endl;
	cin >> n ; 
	int x ; 
	bool f = false ;
	for (i = 0 ; i <a.size(); i++ ) 
		{
			x =  n - a[i] ; 
			if ( x < 0 ) 
				break; 
			int c = lower_bound(a.begin() , a.end() , x) - a.begin();
			if ( a[c] + a[i] == n ) 
			{
				f = true;
				//cout << x << endl;
			}
	    }

	if ( f ) 
		cout << "YES" << endl;
	else 
		cout << "NO" << endl;
	
	return 0;
}