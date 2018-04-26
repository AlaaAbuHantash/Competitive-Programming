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
#include <stdio.h>
#include <fstream>
#define mp make_pair
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int t, tt = 1, n, d, m, x, y, res;
vector<pair<int, pair<int, int> > > p;
vector<int> parent;
int find(int u) {
	if (u == parent[u])
		return u;
	return parent[u] = find(parent[u]);
}

int main() {

	//freopen("A.txt", "r", stdin);
	//freopen ("myfile.txt","w",stdout);

	scanf("%d", &t);
	while (t--) {
		p.clear();
		scanf("%d%d", &n, &m);
		parent.clear();
		parent.resize(n);
		res = 0;
		for (int i = 0; i < n; i++)
			parent[i] = i;
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &x, &y, &d);
			p.push_back(mp(d, mp(x - 1, y - 1)));
			res += d;
		}
		sort(p.rbegin(), p.rend());
		int len = p.size();
		for (int i = 0; i < len; i++) {
			if (find(p[i].second.first) != find(p[i].second.second)) {
				parent[find(p[i].second.first)] = find(p[i].second.second);
				res -= p[i].first;
			}
		}
		printf("%d\n",res);
	}
	scanf("%d", &t);
	return 0;

}


