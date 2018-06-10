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
int main ()
{
	int arr[5][5];
	int i , j , c = 0 ,a ,b ,n=0;

	for (i=0 ; i < 5 ; i++)
		for (j=0; j<5 ; j++)
		{
			cin>> arr[i][j] ; 
			if(arr[i][j]==1)
			{
				a=i;b=j;
			
			}
		}

		//cout << a<<b<<endl;
		if(a>2)
			n=a-2;
		else if(a<2)
			n=2-a;

		if(b>2)
			n=n+b-2;
		else if(b<2)
			n=n+2-b;

		cout<<n<<endl;

}

