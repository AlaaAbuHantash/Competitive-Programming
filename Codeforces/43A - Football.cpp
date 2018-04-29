#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string> 
using namespace std;

int main()
{

	int n , i , j; 
	cin >> n ;
	vector< string > s(n+1);
	vector <int> r (n+1) ; 

	for ( i = 0 ; i < n ; i++)
	{
		cin >>s[i] ;
		r[i]=0;
	}
		for ( i = 0 ; i < n ; i++)
		{
			for ( j = 0 ; j < n ; j++)
			{
				if( s[j] == s[i])
					r[i]++; 
			
			}
		}

		int x = 0 ; 
		for ( i = 0 ; i < n ; i++)
		   if(r[i]>x)
		   {
			   x = r[i];
			   j=i;
		    
		   }


		   cout << s[j]<<endl;
}

