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
	int t  ,x , y  , a ,n; 
	cin >> t ; 
	bool f, s ; 
	while (t--)
	{
		f= false ; 
		s = false ;
		cin >> n >> x >> y ;
		for (int i = 0 ; i < n ; i++) 
		{
			cin >> a ; 
			if(i==0 ) 
			{
				if ( x == a ) 
					f = true;
			}
			if ( i == n-1 ) 
			{
				if ( y == a ) 
					s = true;
			}
		}


		if ( s && f ) 
			cout << "BOTH" << endl;
		else if ( !s && !f ) 
			cout << "OKAY" << endl;
		else if ( s && !f ) 
			cout <<"HARD"<<endl;
		else if ( !s && f ) 
			cout << "EASY" <<endl;
	}
	return 0;
}
