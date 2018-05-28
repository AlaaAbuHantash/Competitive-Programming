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
	int i  , y =0, u=0; 

	cin >> s ; 
	if(isupper(s[0]))
		u++;
	else 
		y++;
	for (i = 1 ; i < s.length() ; i++)
	{
		if(isupper(s[i]))
			u++;
		//cout <<"y"<< y << s[i] << endl;
	}

	if (u==s.length())
	{
	 for (i = 0 ; i < s.length() ; i++)
		  s[i]=tolower(s[i]);
		  cout << s << endl;
	}

	else if (u+1 == s.length() && y==1 )
	{
    	s[0]=toupper(s[0]);
       for (i = 1 ; i < s.length() ; i++)
		 s[i]=tolower(s[i]);

	   	cout << s << endl;
	}
	else 
	{
		cout << s << endl;
	}
}


