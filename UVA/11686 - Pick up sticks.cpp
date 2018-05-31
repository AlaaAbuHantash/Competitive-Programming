#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
int main(int argc, char **argv) {
	//freopen("a.txt", "r", stdin);
	int n, m;
	while (scanf("%d%d", &n, &m) && n && m) {
		int cnt = 0;
		vector<int> in(n);
		vector<int> vis(n);
		vector<vector<int> > v(n);
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			a--, b--;
			in[b]++;
			v[a].push_back(b);
		}
		priority_queue<int> pq;
		for (int i = 0; i < n; i++) {
			if (in[i] == 0) {
				pq.push(i);
				vis[i] = 1;
			}
		}
		vector<int> res;
		while (!pq.empty()) {
			int t = pq.top();
			pq.pop();
			vis[t] = 1;
			res.push_back(t);
			for (int i = 0; i < v[t].size(); i++) {
				in[v[t][i]]--;
				if (in[v[t][i]] == 0 && !vis[v[t][i]]) {
					pq.push(v[t][i]);
				}
			}
		}
		if (res.size() == n) {
			for (int i = 0; i < res.size(); i++) {
				printf("%d\n", res[i] + 1);
			}
		} else
			puts("IMPOSSIBLE");

	}
	return 0;
}
