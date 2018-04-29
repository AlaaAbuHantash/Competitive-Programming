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
	string s ; 
	cin >> s; 
	for ( int i =  0; i < s.length() ; i++) {
		if ( s[i] == '.' ) 
			cout << 0 ; 
		else {
			if ( s[i+1] == '.' ) 
				cout << 1 ; 
			else 
				cout << 2 ; 
			i++;
		}
	}

	cout << endl;
	return 0;
}
