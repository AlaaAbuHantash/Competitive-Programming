#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include<stdio.h>
using namespace std;
int main()
{
	string s , t="";
	int i ; 
	bool f = 1  ;
	cin >> s ;
	for (i=0; i<s.length() ; i++ )
	{
		f = 1 ; 
		if ( s[i] == 'W')
			{
				if(s[i+1] == 'U')
				 {
					 if(s[i+2] == 'B')
					 { t = t + " " ;i++;i++; f = 0 ;}
				}
            }

		if(f)
			t = t + s[i] ;

	}


	cout << t << endl;	
	return 0;
}