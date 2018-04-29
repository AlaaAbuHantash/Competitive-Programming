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
using namespace std;
int main()
{
	int n , x ;
	string s ; 

	cin >> n ; 
	while (n--)
	{
		cin >> s ;
		x=s.length();
		if (x>10)
		cout << s[0] << x-2 << s[x-1]<<endl;
		else 
			cout << s <<endl;
	}

}
