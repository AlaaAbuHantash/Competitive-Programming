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
#define mp make_pair
#define eps 1e-6
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int vis[20005];
int main() {
	//freopen("a.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);

	int n, a, b;

	cin >> n;
	vector<pair<int, int> > p;
	while (n--) {
		cin >> a >> b;
		p.push_back(mp(a, b));
	}
	sort(p.begin(), p.end());
	int c = 0;
	for (int i = 0; i < p.size(); i++) {
		if (vis[i])
			continue;
		c++;
		int pre = i;
		for (int j = i + 1; j < p.size(); j++)
			if (!vis[j] && p[pre].second <= p[j].first)
				pre = j, vis[j] = 1;
	}
	printf("%d\n",c);
	return 0;
}

