#include <bits/stdc++.h>
using namespace std;
int n;
int cap[101][101];
int vis[101];
int st, ed, m;
int p[101];
int dfs(int nod, int mn) {

	if (nod == ed)
		return mn;
	vis[nod] = 1;
	int r = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i] && cap[nod][i] > 0) {
			p[i] = nod;
			if (mn == -1)
				r = max(r, dfs(i, cap[nod][i]));
			else
				r = max(r, dfs(i, min(cap[nod][i], mn)));
			vis[i] = 1;
			if (r)
				break;
		}
	}
	return r;
}
int maxflow() {
	int mxflow = 0;
	while (1) {
		memset(vis, 0, sizeof(vis));
		int res = dfs(st, -1);
		if (!res)
			break;
		int nod = ed;
		while (p[nod] != -1) {
			cap[p[nod]][nod] -= res;
			cap[nod][p[nod]] += res;
			nod = p[nod];
		}
		mxflow += res;

	}
	return mxflow;
}
int main(int argc, char **argv) {

	//freopen("a.txt", "r", stdin);
	int t = 1;
	while (scanf("%d", &n) && n) {
		memset(vis, 0, sizeof(vis));
		memset(cap, 0, sizeof(cap));
		memset(p, -1, sizeof(p));
		scanf("%d%d%d", &st, &ed, &m);
		for (int i = 0; i < m; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			cap[a][b] += c;
			cap[b][a] += c;

		}
		printf("Network %d\n", t++);
		printf("The bandwidth is %d.\n\n", maxflow());
	}
	return 0;
}
