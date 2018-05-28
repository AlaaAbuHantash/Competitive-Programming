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

	int n ,j; 
	cin >> n ;
	vector <int> i (n+1) ;
	vector <int> p (n+1) ;
	for (j=1 ; j<=n ; j++)
	{
			cin >> i[j];
			p[i[j]] = j;
	}

	for (j=1; j<=n ; j++)
		cout << p[j] <<" " ;
	cout << endl;

}
