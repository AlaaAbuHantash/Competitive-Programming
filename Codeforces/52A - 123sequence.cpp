#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include<string>
using namespace std;
int main()
{

	int n  , i  , c1 = 0, c2 = 0 , c3 = 0 , max , r ;

	cin >> n ; 
	max = 0 ;
	vector<int> a (n);
	for ( i = 0 ; i < n ; i++) 
		{
			cin >> a[i] ; 
			if (a[i] == 3) c3++ ; 
			if (a[i] == 2 ) c2++;
			if ( a[i] ==1 ) c1++;

	     }
			if ( c2 > max ) max = c2 ; 
			if ( c3 > max ) max = c3 ;
			if ( c1 > max ) max = c1 ; 

	if ( max == c3 ) r = c2 + c1 ; 
	else if ( max == c2 ) r = c3 + c1 ; 
	else if( max == c1) r = c2 + c3 ; 

	cout << r << endl;

	}