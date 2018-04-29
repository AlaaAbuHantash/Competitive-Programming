#include<iostream>
#include<string>
#include <stdlib.h>
#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;
#define mp make_pair
int main() {
	freopen("input.txt" , "rt" , stdin);
 	freopen ("output.txt","w",stdout);

	int t, x, y,r;
	cin >> t;
	r= t;
	cin >> x >> y;
	if ( x == r )r = y ;
	else if ( y == r ) r = x;
	cin >> x >> y;
	if ( x == r )r = y ;
	else if ( y == r ) r = x;
	cin >> x >> y;
	if ( x == r )r = y ;
	else if ( y == r ) r = x;
	cout << r << endl;
	return 0;
}

