#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
vector<vector<int> > v;
int m, n, ans;
vector<int> vis;
int instack[1001];
int low[1001];
int id[1001];
int nub;
void calc(int ind, stack<int> &st) {
	id[ind] = low[ind] = nub++;
	vis[ind] = 1;
	instack[ind] = 1;
	st.push(ind);
	for (int i = 0; i < v[ind].size(); i++) {
		int ch = v[ind][i];
		if (!vis[ch]) {
			calc(ch, st);
			low[ind] = min(low[ind], low[ch]);

		} else if (instack[ch]) {
			low[ind] = min(low[ind], low[ch]);
		}
	}
	if (low[ind] == id[ind]) {
		int cur = st.top();
		do {
			cur = st.top();
			st.pop();
			instack[cur] = 0;
		} while (cur != ind);
		ans++;
	}
}
int main() {
	//freopen("a.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		memset(instack, 0, sizeof(instack));
		memset(id, 0, sizeof(id));
		memset(low, 0, sizeof(low));
		nub = 1;
		v.clear();
		vis.clear();
		v.resize(n + 1);
		vis.resize(n + 1);
		int a, b;
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &a, &b);
			v[a].push_back(b);
		}
		int tmp;
		stack<int> tt;
		scanf("%d", &tmp);
		ans = 0;
		for (int i = 1; i <= n; i++)
			if (!vis[i])
				calc(i, tt);
		printf("%d\n", ans);
	}

}

