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
#include <math.h>
#include<cstdio>
#include<deque>
#include<sstream>
/*YOU got a DREAM, YOU gotta protect it. */
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int main() {
	//freopen("input" , "rt" , stdin);
	//freopen ("myfile.txt","w",stdout);
	int a ,  b  , j ;
	cin >> a >> b ;
	j = a ;
	for ( int i = 0  ; i < b ; i++ ,j--)
		cout << j << " " ;
	for ( int i = 1; i<=j ; i++ )
		cout << i << " " ;

	return 0;
}

