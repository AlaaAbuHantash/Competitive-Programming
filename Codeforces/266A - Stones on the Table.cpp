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

	int n, i , c = 0; 
	string s ; 

	cin >> n >> s ; 

	for (i = 1 ; i < n ; i++)
	{
		if (s[i-1] == s[i])
			c++ ;
	
	
	}
	cout << c << endl;
}


