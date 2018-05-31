#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
int n, m;
int p[200002];
struct edge {
	int from, to, c;
	edge(int from, int to, int c) :
			from(from), to(to), c(c) {
	}
	bool operator < ( const edge & e ) const {
		return c <= e.c;
	}
};
vector<edge> v;
int findp(int x) {
	if (p[x] == x)
		return x;
	return p[x] = findp(p[x]);
}
int mst() {
	priority_queue<edge> pq;
	int sum = 0;
	for (int i = 0; i < m; i++) {
		pq.push(v[i]);
	}
	int nub = 0;
	while (!pq.empty() && nub != n - 1) {
		edge tmp = pq.top();
		pq.pop();
		int a = findp(tmp.from);
		int b = findp(tmp.to);
		if (a != b) {
			p[a] = p[b];
			sum -= tmp.c;
			nub++;
		}
	}
	return sum;
}
int main(int argc, char **argv) {
	//freopen("a.txt", "r", stdin);
	while (scanf("%d%d", &n, &m) && n && m) {
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}
		v.clear();
		int total = 0;
		for (int i = 0; i < m; i++) {
			int x, y, c;
			scanf("%d%d%d", &x, &y, &c);
			v.push_back(edge(x, y, -c));
			total += c;
		}

		printf("%d\n", total - mst());
	}
	return 0;
}
