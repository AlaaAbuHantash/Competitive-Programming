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
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
map<int, int> m;
map<int, int> vis;
vector<int> v;
int main() {
	//freopen("test.txt", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);
	int x, n;
	scanf("%d", &n);
	priority_queue<pair<int, int> > p;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (!vis[x])
			v.push_back(x);
		vis[x] = 1;
		m[x]++;
	}
	for (int i = 0; i <v.size(); i++)
		p.push(mp(m[v[i]], v[i]));
	vector<vector<int> > res;
	while (p.size() >= 3) {
		vector<int> r(3);
		for (int i = 0; i < 3; i++) {
			r[i] = p.top().second;
			m[r[i]]--;
			p.pop();
		}
		for (int i = 0; i < 3; i++)
			if (m[r[i]] > 0)
				p.push(mp(m[r[i]], r[i]));
		sort(r.rbegin(), r.rend());
		res.push_back(r);

	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < 3; j++)
			printf("%d ", res[i][j]);
		puts("");
	}
	return 0;
}

