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
	string b , a ;
	cin >> a >> b ;


		int i = 0 ,c=0;
		for (i=0 ; i< a.length() ; i++)
			if(a[i]!=b[i])c++;
	
	sort(a.begin() , a.end());
		sort(b.begin() , b.end() );


		if(a != b || (a.length() != b.length()) || c>3)
			cout << "NO"<<endl;
		else 
			cout << "YES"<<endl;

}


