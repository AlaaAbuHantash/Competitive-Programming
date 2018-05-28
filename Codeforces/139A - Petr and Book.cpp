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

	int n ,w[7] , i , sum=0;

	cin >> n ;
	for (i=0;i<7;i++)
		cin >> w[i];


	for(i=0 ; sum <= n ;i++)
	{
		if(i==7)
			i=0;

		sum = sum+w[i];

		if(sum==n)
			i--;
	
	
	}
	cout << i << endl;
}
