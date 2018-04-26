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
int n;
vector<int> p;
int find(int x) {
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x];
}
int main() {
	//freopen("a.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b, c;
	while (cin >> n) {
		p.clear();
		p.resize(n);
		for (int i = 0; i < n; i++)
			p[i] = i;
		priority_queue<pair<int, pair<int, int> > > q;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> c;
				if (c >= 0 && i != j)
					q.push(mp(-c, mp(i, j)));
			}
		int res = 0;
		while (!q.empty()) {
			c = -q.top().first;
			a = q.top().second.first;
			b = q.top().second.second;
			q.pop();
			//cout << c << " " << a << " " << b << endl;
			if (find(a) != find(b)) {
				res += c;
				p[find(p[b])] = find(p[a]);
				//	p[a] = find(p[a]);
			//	cout << res << endl;
			} else {
				p[find(p[b])] = find(p[a]);
				//p[b] = a;
			}

		}
		printf("%d\n", res);
	}
	return 0;
}

