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
int main()
{
	int i ; 
	string a , b ; 
	cin >> a >> b ; 
	for (i=0 ; i< a.length() ; i++)
		if (a[i]==b[i])
			cout << 0 ; 
		else 
			cout << 1 ; 

	cout << endl;
}

