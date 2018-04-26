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
int dist[555][3];
int main() {
	//freopen("A.txt", "rt", stdin);
	int n, r, a, b, c, tt = 1;
	vector<vector<pair<int, int> > > v;
	while (scanf("%d%d", &n, &r) > 0) {
		v.clear();
		v.resize(n);
		for (int i = 0; i < r; ++i) {
			scanf("%d%d%d", &a, &b, &c);
			v[a].push_back(mp(b, c));
			v[b].push_back(mp(a, c));
		}
		priority_queue<pair<pair<int, int>, int> > pq;
		pq.push(mp( mp(0, 0), 0));

		for (int i = 0; i < 501; i++)
			for (int j = 0; j < 2; j++)
				dist[i][j] = 2e9;
		dist[0][0] = 0;
		int res = -1;
		while (!pq.empty()) {
			int d = -pq.top().first.first;
			int nod = pq.top().first.second;
			int f = pq.top().second;
			pq.pop();
			if (nod == n - 1 && f == 0) {
				res = d;
				break;
			}


			if (d > dist[nod][f])
				continue;
			for (int i = 0; i < v[nod].size(); ++i) {
				int nn = v[nod][i].first;
				int ct = v[nod][i].second;
				if (dist[nn][!f] > dist[nod][f] + ct) {
					dist[nn][!f] = dist[nod][f] + ct;
					pq.push(mp(mp(-dist[nn][!f], nn), !f));
				}

			}
		}
		printf("Set #%d\n", tt++);
		if (res == -1)
			puts("?");
		else
			printf("%d\n", res);

	}
	return 0;
}

