#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
int main()
{
	int i , t , m = 10000 , x , f  ; 
	cin>> t ; 
	vector <int > a (t) ;

	for(i=0;i<t;i++)
		cin>>a[i] ; 

	for ( i = 1; i < t ; i++) 
	{
		x = abs(a[i-1] - a[i] );
		if (x < m ) 
			{
				m = x ; 
				f = i  ; 
		    }
	}

	int f2 = f + 1   ; 

	x= abs( a[t-1] - a[0] ) ;
	if ( x < m) 
	{
		f = t ; 
		f2 = 1 ; 
	}

	cout << f << " " << f2 << endl;
} 