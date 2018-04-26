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
int dist[10004];
int dist2[10004];
int main() {
	//freopen("A.txt", "rt", stdin);
	int n, m, s, d, p, t, a, b, c;
	scanf("%d", &t);
	vector<vector<pair<int, int> > > v, v2;
	vector<pair<pair<int, int>, int> > vv;
	while (t--) {
		scanf("%d%d%d%d%d", &n, &m, &s, &d, &p);
		v.clear();
		v.resize(n + 1);
		v2.clear();
		v2.resize(n + 1);
		vv.clear();
		for (int i = 0; i < m; ++i) {
			scanf("%d%d%d", &a, &b, &c);
			if (c > p)
				continue;
			v[a].push_back(mp(b, c));
			v2[b].push_back(mp(a, c));
			vv.push_back(mp(mp(a, b), c));
		}
		priority_queue<pair<int, int> > pq;
		pq.push(mp(0, s));

		for (int i = 0; i < n + 1; i++)
			dist[i] = -1, dist2[i] = -1;
		dist[s] = 0;
		dist2[d] = 0;
		int res = -1;
		while (!pq.empty()) {
			int cc = -pq.top().first;
			int nod = pq.top().second;
			pq.pop();
			if (cc > dist[nod])
				continue;

			for (int i = 0; i < v[nod].size(); ++i) {
				int nn = v[nod][i].first;
				int ct = v[nod][i].second;

				if (dist[nn] == -1
						|| (dist[nn] >= dist[nod] + ct && dist[nod] + ct <= p)) {
					dist[nn] = dist[nod] + ct;
					pq.push(mp(-dist[nn], nn));
				}

			}
		}

		while (!pq.empty())
			pq.pop();
		pq.push(mp(0, d));
		while (!pq.empty()) {
			int cc = -pq.top().first;
			int nod = pq.top().second;
			pq.pop();
			if (cc > dist2[nod])
				continue;

			for (int i = 0; i < v2[nod].size(); ++i) {
				int nn = v2[nod][i].first;
				int ct = v2[nod][i].second;
				if (dist2[nn] == -1
						|| (dist2[nn] >= dist2[nod] + ct && dist2[nod] + ct <= p)) {
					dist2[nn] = dist2[nod] + ct;
					pq.push(mp(-dist2[nn], nn));
				}

			}
		}

		while (!pq.empty())
			pq.pop();

		m=vv.size();
		for (int i = 0; i < m; i++) {

			a = vv[i].first.first;
			b = vv[i].first.second;
			c = vv[i].second;

			if (dist[a] != -1 && dist2[b] != -1 && dist[a] + c + dist2[b] <= p)
				res = max(res, c);
		}

		if (res == -1)
			puts("-1");
		else
			printf("%d\n", res);

	}
	return 0;
}

