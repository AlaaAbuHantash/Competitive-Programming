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
	int n ; 
	cin >> n ; 
	vector<int > a ( n) ; 
	for ( int i = 0 ;i < n ; i ++) 
		cin>> a[i] ; 
	bool f = false;
	for ( int  i = 0 ; i < n ; i++) {
		for ( int j = 0 ; j<n ; j++) {

			for ( int k = j +1 ; k < n ; k++) {
				if ( a[i] == a[j] + a[k] ) {
					cout << i +1<< " " << j +1<< " " << k +1<< endl;
					f=true;
					break;
				}
			}
			if ( f) break;
		}
		if ( f ) break;
	}


	if (!f ) 
		cout << -1 << endl;


	return 0;
}
