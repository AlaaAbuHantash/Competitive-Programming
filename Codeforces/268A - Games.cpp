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
	int n , c  =0;
	cin >> n ; 
	vector <int > b (n) ; 
	vector <int > a (n) ;
	for ( int i = 0; i < n ; i ++ ) 
	{
		cin >> a[i]  >> b[i] ; 

	}

	for ( int i = 0 ; i < n ; i++) 
	{
		for ( int j = 0 ; j < n ; j ++ ) 
			if ( a[i] == b[j] ) 
				c++;
	}
	cout << c << endl;
	return 0;
}
