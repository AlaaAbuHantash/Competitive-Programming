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
#include <stdio.h>
using namespace std;
int main()
{
	
	//freopen("test.in" , "rt" , stdin);
	int t ;
	unsigned long long c = 0 , n; 
	cin >> t ; 
	string s ;
	char cur;
	bool f = false  , fl = false;
	while ( t-- ) 
	{
		cin >> s ; 
		c=1;
		n=0;
		f = false;
		fl = false;
		cur = s[0];
		for ( int i = 0 ; i < s.length() ; i++ ) 
		{

			if ( s[i] >= 'a' && s[i] <= 'z' ) 
			{
				fl = true;
				if (f) 
				{
					if ( s[i] != cur  && cur != '?') 
					{
						c = c *(n + 1 );
						c = c % 1000000007 ; 
					}
					n = 0 ; 
					f = false ;
				}
			}
			else if ( s[i] == '?' ) 
			{
				f = true;
				if ( fl ) 
				{
					cur = s[i-1];	
					fl = false ;
				}
				n++;
			}
		}

		c = c % 1000000007 ; 
		cout << c << endl;
	}

	return 0;
}
