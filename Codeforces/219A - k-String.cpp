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
	string s ; 
	int n ; 

	cin >> n >> s ;
	if (s.length()% n != 0 )
	{
		cout << -1<<endl; 
		return 0 ;
	}

	map <char , int > w ;
	map<char ,int> ::iterator it;
	int i ;
	for ( i = 0 ; i < s.length() ; i++)
	{
		w[s[i]]++;
	}

	int x ,z=0;
	x = w[s[0]];
	for (it = w.begin() ; it != w.end() ; it++)
	{
		if (w[it->first] % n != 0)
		{
			cout << -1<<endl;
		    return 0 ; 
		}


	}

	int j ;
   	for (i=0 ; i < n ; i++)
		for (it = w.begin() ; it != w.end() ; it++)
			for (j=0 ; j < w[it->first]/n ; j++)
				cout <<it->first;


	cout << endl;


//http://codeforces.com/problemset/problem/219/A

}
