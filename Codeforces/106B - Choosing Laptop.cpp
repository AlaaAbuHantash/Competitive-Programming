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
#define mp make_pair
#define eps 1e-9
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int vis[111];
int main() {
	//freopen("test.txt", "rt", stdin);
	int n, a, b, c, d;
	scanf("%d", &n);
	vector<pair<pair<int, int>, pair<int, int> > > p;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		p.push_back(mp(mp(a, b), mp(c, d)));
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (p[i].first.first < p[j].first.first
					&& p[i].first.second < p[j].first.second
					&& p[i].second.first < p[j].second.first
					&& p[i].second.second < p[j].second.second)
				vis[i] = 1;
		}
	}
	int cost = 1000 + 1;
	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (!vis[i] && p[i].second.second < cost) {
			cost = p[i].second.second;
			res = i + 1;
		}
	}
	printf("%d\n", res);
	return 0;
}

