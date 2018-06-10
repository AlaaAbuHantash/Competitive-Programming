#include <cstdio>
#include<stdio.h>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string> 
#include<sstream>
#include <map> 
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
	long long int i , x = 1 ,r=0 , c=0 ,n=0; 
	string s ; 
	cin >> s ;
	map<char , int > v ;

	for (i=0 ; i < s.length() ;i++)
	{
		if(s[i] == '?' )
		{
			if(i==0)
				x=x*9;
			else 
			   n++;

			//cout << x <<endl;
		}
		else if (s[i] == 'A' ||s[i] == 'B' ||s[i] == 'C' ||s[i] == 'D' ||s[i] == 'E' ||s[i] == 'F' ||s[i] == 'G' ||s[i] == 'H' ||s[i] == 'I' ||s[i] == 'J' )
		{
			if( v[s[i]] != 1 &&  i == 0 )
			{
				x=x*(9-c);
				c++;
			}
			else if( v[s[i]] != 1 )
			{
				x=x*(10-c ) ;
				c++;
			}
			v[s[i]]=1;


		}
		else 
		{
			x= x*1;
		}
	}

	 
		cout << x;
		for(i=0 ; i<n ; i++)
			cout << 0;
		cout<<endl;
}

