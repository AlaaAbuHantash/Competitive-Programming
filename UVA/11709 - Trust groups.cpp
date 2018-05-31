#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
int n, m;
map<string, int> id;
vector<vector<int> > v;
int vis[1001];
int val[1001];
int instack[1001];
int cnt;
int lev;
vector<int> st;
void dfs(int nod) {
	vis[nod] = ++lev;
	val[nod] = vis[nod];
	instack[nod] = 1;
	st.push_back(nod);
	for (int i = 0; i < v[nod].size(); i++) {
		int x = v[nod][i];
		if (!vis[x]) {
			dfs(x);
			val[nod] = min(val[nod], val[x]);
		} else if (vis[x] && instack[x])
			val[nod] = min(val[nod], val[x]);
	}

	if (vis[nod] == val[nod]) {
		int x;
		do {
			x = st.back();
			instack[x] = 0;
			st.pop_back();
		} while (x != nod);
		cnt++;
	}

}
int main(int argc, char **argv) {
	//freopen("a.txt", "r", stdin);
	while (scanf("%d%d", &n, &m) && n + m > 0) {
		int ind = 0;
		string a, b;
		lev = 0;
		cnt = 0;
		v.clear();
		v.resize(n);
		id.clear();
		memset(vis, 0, sizeof(vis));
		memset(val, -1, sizeof(val));
		memset(instack, 0, sizeof(instack));

		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			string s = a + b;
			id[s] = ind++;
		}
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			a = a + b;
			int x = id[a];
			cin >> a >> b;
			a = a + b;
			int y = id[a];
			v[x].push_back(y);
		}
		for (int i = 0; i < n; i++) {
			if (!vis[i])
				dfs(i);
		}
		printf("%d\n", cnt);
	}
	return 0;
}
