#include <bits/stdc++.h>
using namespace std;
struct edge {
	int a, b, c;
	bool operator <(const edge &v) const {
		return c < v.c;
	}
} E;
int p[1001];
int n, m;
int find(int x) {
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}
int main() {
	//freopen("a.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		int total = 0;
		priority_queue<edge> pq;
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &E.a, &E.b, &E.c);

			total += E.c;
			E.c = -E.c;
			pq.push(E);
		}
		for (int i = 0; i < n; i++)
			p[i] = i;
		int nub = 0;
		while (!pq.empty() && nub != n - 1) {
			int a = pq.top().a;
			int b = pq.top().b;
			int c = -pq.top().c;
			pq.pop();
			if (find(a) != find(b)) {
				p[find(a)] = p[find(b)];
				nub++;
				total -= c;
			}
		}
		printf("%d\n", total);
		while (!pq.empty())
			pq.pop();
	}
	return 0;
}

