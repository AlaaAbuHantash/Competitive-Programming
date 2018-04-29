#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include<string>
#include<iomanip>
#include<set>
#include<stack>
using namespace std;
int main()
{ 
	int n  , t , i  , temp , c , j; 
	vector <int> a ;
	cin >> t ; 
	while ( t--) 
	{
		cin >> n ; 
		a.resize(n);
		c= 0 ;
		for ( i = 0 ; i < n ; i++ ) cin >> a[i] ; 

		for ( i = 0 ; i < n ; i++ )
			for ( j = i+1 ; j < n ; j++ )
			{
				if ( a[i]>a[j] )
				{
					temp = a[i] ; 
					a[i] = a[j] ; 
					a[j ] = temp; 
					c++ ;
				
				}
			}


			cout << "Optimal train swapping takes " << c <<" swaps." <<endl;

		
		a.clear();
	}
}