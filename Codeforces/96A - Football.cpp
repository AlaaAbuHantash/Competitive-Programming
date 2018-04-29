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
	int x , y;
	string s ; 

	cin >> s ;
	x = s.find("0000000",0);
	y = s.find("1111111",0);

	if ( s.find("0000000",0) != string::npos || s.find("1111111",0) != string::npos ) 
		cout << "YES"<<endl;
	else 
		cout << "NO"<<endl;
}
