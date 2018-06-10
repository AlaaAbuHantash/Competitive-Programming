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
double ma[111];
int main() {
	//freopen("input", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);
	int n, x = 1;
	cin >> n;
	vector<int>v ;

	v.push_back(0);
	v.push_back(1);
	while (1) {
		v.push_back(v[x] + v[x-1]);
		if(v[x] > 1000000000)break;
		x++;

	}
	bool f =0;
	for ( int i = 0 ; i < v.size() ; i++)
		for ( int j = 0 ; j < v.size(); j++)
			for ( int k = 0 ; k <v.size() ;k++)
				if ( v[i] + v[j] + v[k] == n ) {
					f=1;
					printf("%d %d %d\n",v[i],v[j] , v[k]);
					return 0 ;
				}

	puts("I'm too stupid to solve this problem");
	return 0;
}

