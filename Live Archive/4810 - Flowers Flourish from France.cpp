
#include <cstdio>
#include <iostream>
#include<string>
#include<vector>
#include<cstring>
#include<cctype>
#include <algorithm>

using namespace std; 

 
int main()
{
     int  i  ;
	int z, w, y   ; 
	string s , x ; 
	while (getline (cin , s))
	{
		w = 0 ;
		z = 0 ;
	    y = 0 ;
		if (s == "*" ) 
			break ; 
		else 
		{
			for ( i = 0 ; i < s.length() ; i = z) 
			{
			    z = s.find(" ", i+1);
				    w++;
				x =	s.substr(z+1 , 1 );
               if ( toupper(x[0]) == toupper(s[0]))  
			           	 y++;	
			}

			if ( w == y)
				cout <<"Y" << endl; 
			else 
				cout << "N"<< endl; 

	
		}
	
	}
		
	

return 0;
}

