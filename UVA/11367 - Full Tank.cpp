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
int p[1111];
int dist[1111][111];
vector<vector<pair<int, int> > > v;
int main() {
	//freopen("A.txt", "rt", stdin);
	int n, m, x, a, b, c, q;
	scanf("%d%d", &n, &m);
	v.resize(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &p[i]);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		v[a].push_back(mp(b, c));
		v[b].push_back(mp(a, c));
	}
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		scanf("%d%d%d", &c, &a, &b);
		for (int j = 0; j < n; j++)
			for (int k = 0; k < 101; k++)
				dist[j][k] = 2e9;
		priority_queue<pair<pair<int, int>, int> > q;
		q.push(mp(mp(0, a), 0));
		dist[a][0] = 0;
		int res = -1;
		while (!q.empty()) {
			int cst = -q.top().first.first;
			int nod = q.top().first.second;
			int ff = q.top().second;

			q.pop();
			if (nod == b) {
				if (res == -1)
					res = cst;
				res = min(res, cst);
				break;
			}

			if (cst > dist[nod][ff])
				continue;

			for (int j = 0; j < v[nod].size(); j++) {
				int nnod = v[nod][j].first;
				int cc = v[nod][j].second;
				if (cc <= ff) {
					if (dist[nnod][ff - cc] > dist[nod][ff]) {
						dist[nnod][ff - cc] = dist[nod][ff];
						q.push(mp(mp(-dist[nnod][ff - cc], nnod), ff - cc));
					}
				}
			}

			if (ff + 1 <= c) {
				dist[nod][ff + 1] = dist[nod][ff] + p[nod];
				q.push(mp(mp(-dist[nod][ff + 1], nod), ff + 1));
			}
		}
		if (res != -1)
			printf("%d\n", res);
		else
			puts("impossible");
	}
	return 0;
}

