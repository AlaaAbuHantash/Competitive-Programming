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
	int a , b , n ;
	cin >> n ;
	vector<pair<int, int > > p ;
	for ( int i = 0 ; i < n ; i++){
		cin >> a >> b ;
		p.push_back(make_pair(a,b));
	}
	bool f =  0 ;
	sort(p.begin() , p.end());
	for ( int i = 1 ; i < n ; i++)
		if (p[i-1].second > p[i].second){
			f=1;break;
		}
	if (f)
		puts("Happy Alex");
	else
		puts("Poor Alex");
	return 0;
}

