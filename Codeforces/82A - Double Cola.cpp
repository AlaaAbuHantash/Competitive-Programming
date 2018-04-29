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
	int n ,i ,x=5 , c=1;
	cin >> n ; 
	string s[5]={"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
	n--;
	for ( ; n >= x ; )
	{

		n = n- x ;
		x = x*2;
		c = c*2;
	}

	int a = n/c ;

	cout << s[a] <<endl;

}


