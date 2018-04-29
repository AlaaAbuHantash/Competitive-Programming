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

  //	freopen("test.in" , "rt" , stdin);
	string s , t  ,r = "" ;  
	vector <string > a (11) ; 
	cin >> s ; 

	 for ( int i = 0 ; i < 10 ; i++)
		{
			cin >> a[i];
			//a[i] = a[i].substr(0,8);
	    }

	 for ( int j = 0 ; j < s.length() ; j = j + 10) 
	 {
		 t = s.substr(j,10);
		// cout << t << endl;
		 for (int i = 0 ; i < 10 ; i++) 
		 {
			 if ( t == a[i] ) 
			 {
				 r = r + char('0' + i) ;
				// cout << r << endl;
					 break;
			 }
		 }
	 }

	 cout << r << endl;
	return 0;
}
