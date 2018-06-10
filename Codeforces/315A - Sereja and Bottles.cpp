#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <utility> 
#include <stack>
#include <cstring> 
using namespace std;
int main()
{
	
//  freopen("test.in" , "rt" , stdin);

	int t ;
	cin>>t;
	vector <int > a(t);
	vector <int > b(t);
	for ( int i = 0 ;i < t ; i++ )
		cin >> a[i] >> b[i] ; 
	//sort(a.begin() , a.end() );
	//sort(b.begin() , b.end() );

	int C=0;bool f = false;
	for (int i = 0 ; i < t ; i ++ ) 
	{
		f = false;
		for (int  j = 0 ; j < t ; j ++ ) 
		{

			if (( i == j ) && ( a[i] == b[j] )) 
			    {	
					f = false;
					
			    }
			else if ( a[i] == b[j] ) 
				{
					f = true;
					break;
			    }
		}
	
		if ( !f ) 
			C++;
	}
	cout << C << endl;
	return 0;
}
