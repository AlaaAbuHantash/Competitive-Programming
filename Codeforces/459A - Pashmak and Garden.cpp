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
	int a, b, c, d;
	int x, y;
	int aa, bb, cc, dd;
	cin >> a >> b >> c >> d;
	vector<pair<int, int> > p;
	p.push_back(make_pair(a, b));
	p.push_back(make_pair(c, d));
	bool f = 0;
	sort(p.begin(), p.end());
	if (p[0].first == p[1].first) {
		x = abs(p[0].second - p[1].second);
		aa = p[0].first + x;
		bb = p[0].second;
		cc = p[1].first + x;
		dd = p[1].second;
		f = 1;
	}
	else if (p[0].second == p[1].second) {
		x = abs(p[0].first - p[1].first);
		aa = p[0].first;
		bb = p[0].second + x;
		cc = p[1].first;
		dd = p[1].second + x;
		f = 1;
	}
	else {
		aa = p[0].first;
		bb = p[1].second;
		cc = p[1].first;
		dd = p[0].second;
		x = abs(cc - p[0].first) ;
		y = abs(bb - p[0].second);
		if (x == y)
			f = 1;
	}
	if (f)
		printf("%d %d %d %d\n", aa, bb, cc, dd);
	else
		puts("-1");
	return 0;
}

