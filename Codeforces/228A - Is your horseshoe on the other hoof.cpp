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
	int x = 0 ;
	vector <int> s (4);
	cin>> s[0]>>s[1]>>s[2]>>s[3];
	sort (s.begin() ,  s.end());


		for (int i = 1 ; i<4 ; i++)
			if (s[i-1]==s[i])
				x++;
	cout << x <<endl;
}
