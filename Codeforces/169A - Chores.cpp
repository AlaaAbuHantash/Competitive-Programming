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
#define mp make_pair
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int main() {
	//freopen("input", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);

	int n ,x  , a , b ;
	vector<int > v ;
	cin >> n >> a >> b ;
	for ( int i = 0 ; i < n ; i++){
		cin >> x ;
		v.push_back(x);
	}
	sort(v.begin() , v.end()) ;
	printf("%d\n",v[b]- v[b-1]);

	return 0;
}

