#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string> 
#include<sstream>
#include <map> 
using namespace std;
int main()
{


	string s ; 
	int t,n , i , count , x=1 ;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin >> s ;
		count = 0 ; 
		for (i = 0 ; i < n ; )
		{
			if (s[i] == '#')
				i++;
			else if (s[i]=='.')
			{
				count++; 
				i = i + 3 ; 
			
			}
		}

			cout <<"Case "<<x<<": "<<count << endl;
			x++;
	}




}


