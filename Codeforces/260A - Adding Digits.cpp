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

	int a  , b , n  , x , y , z  ,r; 
	bool f = false;
	cin >> a >> b >> n ; 

	a =a * 10 ; 
	for ( int i = 0 ; i < 10 ; i++ ) {
		//cout << a << endl; 
		if ( a % b == 0 ) {
			f = true; 
			cout << a  ; 
			break;
		}
		a++;
		
	}

	if ( f ) {
		for ( int i = 0 ; i < n-1 ; i++) 
			cout << "0";
	cout << endl;
	}

	if ( !f ) 
		cout << -1 << endl;
	return 0;
}
