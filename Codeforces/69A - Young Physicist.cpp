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
	int i , n , sumx=0 , sumy=0 , sumz=0 ;
	cin >> n  ;
	vector <int> x (n);
	vector <int> y (n);
	vector <int> z (n);

	for (i=0 ; i<n ; i++)
	{
		cin >> x[i] >> y[i] >> z[i];
		sumx = sumx + x[i];
		sumy = sumy + y[i];
		sumz = sumz + z[i];
	}

	if (sumx == 0 && sumy==0 && sumz==0)
		cout << "YES"<<endl;
	else 
		cout << "NO" <<endl;


}

