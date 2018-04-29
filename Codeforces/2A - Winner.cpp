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

	map <string , int> w ;
	
	map <string , int> w2 ;

	map<string ,int> ::iterator it;
	string s[1001]  , r; 
	int t , n[1001] ; 
	cin >> t ;
	int i = 0 ;
	while (t--)
	{
		cin >> s[i]>>n[i];
		w[s[i]]=w[s[i]]+n[i];
		i++;
	}

	int x = 0 ; 
	for (it = w.begin() ; it != w.end() ; it++)
		if (w[it->first] > x)
		{
			//r = it->first ;
			x=w[it->first];
		}

	 for(i=0;w[s[i]]< x || (w2[s[i]]+=n[i]) <x ;i++);
    cout<<s[i]<<endl;


	//cout << r <<endl;


		return 0 ;
}
