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
int main ()
{
	int y, n ,t ; 
	string s; 

	cin >> y ;
	n=y;


	while(1)
	{
		n++;
	
		ostringstream convert; 
		convert << n; 
		s = convert.str();

		if((s[0] != s[1]) && (s[0] != s[2]) && (s[0] != s[3]) && (s[1] != s[2]) && (s[1] != s[3])  && (s[3] != s[2]))
		{
			cout << s <<endl;
			break;
		}


	}


}

