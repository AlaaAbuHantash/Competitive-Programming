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
using namespace std;
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int main() {
	//freopen("test.txt", "rt", stdin);
	int x, y, n, xx=2e9, yy=0;
	cin >> n;
	vector<pair<int, int> > p;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		xx = min(xx, x);
		yy = max(yy, y);
		p.push_back(make_pair(x, y));
	}
	for (int i = 0; i < n; i++) {
		if (p[i].first == xx && p[i].second == yy) {
			cout << i + 1 << endl;
			return 0;
		}
	}
	puts("-1");
	return 0;
}

