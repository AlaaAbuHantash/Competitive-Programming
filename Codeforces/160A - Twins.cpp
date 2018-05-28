#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility> 
#include <stack>
#include <cstring> 
using namespace std;
int main()
{

	int n ,sum = 0 ,c=0;
	cin >> n ;
	vector <int> a ( n ) ; 
	for ( int i = 0 ; i < n ; i ++ ) {
		cin >> a[i] ; 
		sum+=a[i];
	}


	sort(a.begin() ,a.end() ) ; 
	int s = 0 ; 
	for (int j = n-1 ; j >=0 ; j-- ) 
	{
		s+=a[j] ; 
		c++;
		if ( s > sum-s)
			break;
	}

	cout << c << endl;
	return 0;
}
