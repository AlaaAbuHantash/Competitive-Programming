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
	int n  , i,j,t ,x; 
	string s ,z; 
	cin >> n >> t >>s;
	z=s;
	for (x=0 ;x<t ; x++)
	{
		for (j= 1 ; j< n ; j++ )
			{
				if (s[j-1]== 'B' && s[j]== 'G')
				{
					swap(z[j],z[j-1]);
					
			    }
		     }
		
		s=z ;
	
	}

	cout << z << endl;

}
