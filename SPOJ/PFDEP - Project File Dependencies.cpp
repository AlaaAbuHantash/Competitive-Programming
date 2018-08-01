#include <bits/stdc++.h>
using namespace std;
int main() {
	//freopen("a.txt", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	vector<vector<int> > v(n + 1);
	vector<int> in(n + 1);
	for (int i = 0; i < m; i++) {
		int x, k;
		scanf("%d%d", &x, &k);
		in[x] += k;
		for (int j = 0; j < k; j++) {
			int y;
			scanf("%d", &y);
			v[y].push_back(x);
		}
	}
	priority_queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0)
			q.push(-i);
		sort(v[i].begin(), v[i].end());
	}

	vector<int> ans;
	while (!q.empty()) {

		int fr = -q.top();
		ans.push_back(fr);
		q.pop();
		for (int i = 0; i < v[fr].size(); i++) {
			int nxt = v[fr][i];
			in[nxt]--;
			if (in[nxt] == 0) {
				q.push(-nxt);
			}
		}

	}
	printf("%d", ans[0]);
	for (int i = 1; i < n; i++)
		printf(" %d", ans[i]);
	puts("");
	return 0;
}

