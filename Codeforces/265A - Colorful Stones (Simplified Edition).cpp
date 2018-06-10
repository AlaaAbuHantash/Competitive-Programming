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
	//freopen("input", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);
	string a , b ;
	cin >> a >> b ;

	int g = 0 ;
	for ( int i = 0 ; i < b.size() && g < a.size() ; i++) {
			if ( a[g] == b[i]){
				g++;
			}
	}
	cout << g+1 << endl;
	return 0;
}

