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
	map <char , int > v ;
	string s ;
	int i ,x = 0 ;
	cin >> s ; 

	for (i=0 ; i < s.length() ; i++)
		if (v[s[i]] !=  1)
		{
			v[s[i]]=1;
			x++;
		
		}


		if (x%2==0)
			cout <<"CHAT WITH HER!"<<endl;
		else
			cout << "IGNORE HIM!"<<endl;
}
