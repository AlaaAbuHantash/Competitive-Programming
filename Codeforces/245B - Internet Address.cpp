#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
	int i ; 
	string s , r ; 
	bool f = 1;
	cin >> s ; 
	r="";
    i= 0;
	if (s[0] == 'h' ) { r = "http://"; i=4;}
	else if (s[0] == 'f'){r="ftp://" ; i=3;}

	r = r + s[i] ;
	i++;
	for ( ; i < s.length(); i++)
	{
		if (s[i] == 'r' && f)
				{
					if(s[i+1] == 'u' ) 
		            {f = 0 ; r = r + ".ru/" ; i++; }
					else 
		          	r = r + s[i] ;

	          	}
		else 
			r = r + s[i] ;
	}
	
	if (r[r.length() -1 ] == '/' )
		r = r.substr(0 , r.length() -1);
	cout << r << endl;
}