#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include<string>
using namespace std;
int main()
{

	int n  , i ;
	string s , t ; 
	cin >> s ; 
	cout << s[0] ;
	bool f = false , y  , x;
	for (i = 1 ; i < s.length() ;i++)
	{
		 y = 1 ; x = 1 ; 
		if ( s[i]== 'd' && i <= s.length()-4 )
			{
				if(s[i+1] == 'o' ) 
				if(s[i+2] == 't' )
				{	i=i+2; 
				   t = t + ".";
				   y = 0 ; 
				}
	     	}

		else if ( s[i]== 'a'  && !f )
			{
				if(s[i+1] == 't' ) 
				{ t = t + "@";i++; f=true; x = 0 ; }
		     }

		if (x && y ) 
			 t = t + s[i];
		
	}
	cout <<t<< endl;


}