#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{

	int m , n  , i , j , sum  , mi = 0 , m2= 0 , x ; 
	cin >> n >> m ;
	vector<int> k (n);
	vector<int> l (m+1) ;
	vector<int> r (m+1) ;
	for ( i =0 ; i < n ; i++)
		{
			cin >> k[i];
			if ( k[i] == -1 ) 
				mi++;
			else 
				m2++;
	}

	for ( i=0;i<m;i++)
		cin>>l[i] >> r[i];

	for ( i = 0 ; i < m; i++) 
	{
		sum = 0 ; 
		x = r[i] - l[i] + 1 ; 
		if ( x%2 == 0 ) 
		{
			x = x / 2 ; 

			if ( mi >= x  && m2 >= x ) 
				cout << 1<< endl;
			else 
				cout << 0 << endl;
		}
		else
			cout << 0<< endl;
		
	}
	return 0;
}