#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int main() {
	int n , m , x  , a ,b ; 
	cin >> n >> m ; 
	int beg = 0;
	vector < int > v  ; 
	v.push_back(0);
	for ( int i = 0 ; i < n ; i ++ ) { 
		cin >> a >> b ; 
		beg = beg + (a*b); 
		v.push_back(beg);
	}
	for ( int i = 0 ; i < m ; i++){
		cin >> x ; 
		int res = lower_bound (v.begin(), v.end(), x ) - v.begin();

		cout << res << "\n";
	}
	return 0;
}