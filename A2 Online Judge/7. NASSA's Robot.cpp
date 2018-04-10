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
string s ;
int main()
{
	//freopen("test.in" , "rt" , stdin);
	int t  , x , y , x1 ,x2, c , y2 , y1; 

	cin >>t ; 
	while (t--) {
		cin >> s ;
		x =  0 ;y = 0 ; 
		
		c=0;
			for ( int i = 0 ; i < s.length() ; i++ ) {
				if ( s[i] == 'R' ) 
					x++;
				else if ( s[i] == 'L' ) 
					x--;
				else if ( s[i] =='U' ) 
					y++;
				else if ( s[i] == 'D' ) 
				    y--;
				else 
				   c++ ;
			}

			x1 = x + c ; 
			x2 = x -c ; 
			y1 = y + c ; 
			y2 = y - c ; 

			cout << x2 << " " << y2 << " " << x1 << " " << y1 << endl;
	}
    return 0;
}
