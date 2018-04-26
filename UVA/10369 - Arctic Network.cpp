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
#define eps 1e-6
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
vector<int> parent;
int find(int u) {
	if (u == parent[u])
		return u;
	return parent[u] = find(parent[u]);
}
int main() {
	//freopen("A.txt", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);
	int t, s, p, a, b;
	scanf("%d", &t);

	vector<pair<int, int> > v;
	vector<pair<double, pair<int, int> > > v2;
	while (t--) {
		v.clear();

		v2.clear();
		scanf("%d%d", &s, &p);
		parent.clear();
		parent.resize(p + 1);
		for (int i = 0; i < p; i++) {
			scanf("%d%d", &a, &b);
			v.push_back(mp(a, b));
		}
		for (int i = 0; i < p; i++) {
			for (int j = i + 1; j < p; j++) {
				double aa = abs(v[i].first - v[j].first);
				double bb = abs(v[i].second - v[j].second);
				double dist = sqrt((aa * aa) + (bb * bb));
				//cout << dist << endl;
				v2.push_back(mp(dist, mp(i, j)));
			}
			parent[i] = i;
		}
		double res = -1;
		sort(v2.begin(), v2.end());
		int g = p - s;
		for (int i = 0; i < v2.size() && g; i++) {
			if (find(v2[i].second.first) != find(v2[i].second.second)) {
				parent[find(v2[i].second.first)] = find(v2[i].second.second);
				if (res == -1)
					res = v2[i].first;
				res = max(res, v2[i].first);
				g--;
			}
		}
		printf("%.2lf\n", res);
	}
	return 0;
}

