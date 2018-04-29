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
int a, b, n, m;
long long c;
vector<vector<pair<int, long long> > > v;
int path[100005];
long long  dist[100005];
bool vis[100005];
void p(int x) {
	if (x == -1)
		return;
	p(path[x]);
	printf("%d ", x + 1);
}
int main() {
	//freopen("test.txt", "rt", stdin);
	scanf("%d%d", &n, &m);
	v.resize(n);
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < m; i++) {
		scanf("%d%d%lld", &a, &b, &c);
		v[a - 1].push_back(mp(b - 1, c));
		v[b - 1].push_back(mp(a - 1, c));
	}
	dist[0] = 0;
	path[0] = -1;
	priority_queue<pair<long long, int> > pq;
	pq.push(mp(0, 0));
	bool f = 0;
	int st;
	while (!pq.empty()) {
		int fr = pq.top().second;
		long long cot = -pq.top().first;
		pq.pop();
		if (vis[fr])
			continue;
		vis[fr] = 1;
		if (fr == n - 1) {
			f = 1;
			st = fr;
			break;
		}
		for (int i = 0; i < v[fr].size(); i++) {
			long long  w = v[fr][i].second;
			int nod = v[fr][i].first;
			if (dist[fr] + w < dist[nod] || dist[nod] == -1) {
				dist[nod] = dist[fr] + w;
				pq.push(mp(-dist[nod], nod));
				path[nod] = fr;
			}
		}
	}
	if (f)
		p(st);
	else
		puts("-1");
	return 0;
}

