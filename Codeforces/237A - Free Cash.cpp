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

int h [100000] , m [100000];
int main()
{
int x =1 ,j;
int i , n , c=1;

	cin >> n ;
	

	for(i=0 ; i< n ; i++)
	{
		cin >> h[i] >> m[i];
	}



	for(i=1 ; i<n ; i++)
	{
		c=1;
		if (h[i-1]== h[i])
			while (h[i-1]== h[i] && m[i-1]== m[i] && i<n)
			{
				c++;
				i++;
			}
		
			if (c > x)
				x = c ;
	}
	cout << x <<endl;
}

