#include <cstdio>
#include<stdio.h>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string> 
#include <map> 
#include <cmath>
using namespace std;

int main () 
{
	int l  , i , x = 0;
	string s ; 
	bool flag = 0;
	cin >>s ; 
	l = s.length();
	for(i=0; i<l; i++)
	{

		if (s[i] == '4' || s[i] == '7')
		{
			flag=1;
			x++;
		}

	}

	if (flag)
	{
		if(x == 7 || x == 4)
	    	cout << "YES" <<endl;
		else 
			cout << "NO"<<endl;
	}
	else 
		cout << "NO"<<endl;


	return 0 ;
}