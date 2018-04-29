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
	//freopen("test.in" , "rt" , stdin);
	int n  , d ;
	cin >> n  >> d ; 
	int c= 0;
	vector<int> a(n) ; 
	for ( int i = 0 ; i < n ; i ++) 
		cin >> a[i] ; 

	for ( int i= 0 ; i < n ; i ++) 
		for ( int j = 0 ; j < n ; j ++) {
			if (abs( a[j]-a[i]) <= d  && i != j ) 
			   c++ ; 
		}

		cout << c << endl;
	return 0;
}
