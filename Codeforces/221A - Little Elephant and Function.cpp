#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int main() {
	//freopen("input", "rt", stdin);
	// 1 2 3 4 5 ... n
	// 2 1
	// 2 1 3 ->  3 1 2
	// 3 1 2 4 - > 4 1 2 3
	int n ;
	cin >> n ;
	cout << n ;
	for ( int i =1 ; i < n  ; i ++ )
		cout << " " << i  ;

	return 0;
}

