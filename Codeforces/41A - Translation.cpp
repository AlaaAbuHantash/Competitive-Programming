#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string> 
using namespace std;

int main()
{

	int i = 0, x=0 , y  ; 
	string s1 , s2 ; 

	cin >> s1 >> s2 ; 

	y = s1.length() - 1 ; 
	for (i=0 ; i < s1.length() ; i++ )
	{
		if (s1[i] != s2[y] )
		{x=1 ; break;}
		else if (s1[i] == s2[y])
			y--;
	
	
	}
	if(x)
		cout <<"NO"<<endl;
	else
		cout <<"YES"<<endl;




}


