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
#include <stdio.h>
#include <fstream>
#define mp make_pair
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int n, m;
map<string, int> ma;
map<int, string> mg;
vector<vector<int> > sc;
string a, b;
vector<vector<int> > v;
vector<int> low, num, vis;
int cnt;
stack<int> s;
void calc(int u) {
	low[u] = num[u] = cnt++;
	s.push(u);
	vis[u] = 1;
	for (int i = 0; i < v[u].size(); i++) {
		if (num[v[u][i]] == -1) {
			calc(v[u][i]);
		}
		if (vis[v[u][i]])
			low[u] = min(low[u], low[v[u][i]]);
	}

	if (low[u] == num[u]) {
		vector<int> tmp;
		sc.push_back(tmp);
		int xx = sc.size();
		while (1) {
			int x = s.top();
			s.pop();
			sc[xx - 1].push_back(x);
			vis[x] = 0;
			if (x == u)
				break;
		}
	}

}
int main() {

	//freopen("A.txt", "r", stdin);
	//freopen ("myfile.txt","w",stdout);
	int tt = 1, g = 0;
	while (scanf("%d%d", &n, &m) > 0) {
		if (n + m == 0)
			return 0;
		if (g)
			puts("");
		g = 1;
		ma.clear();
		mg.clear();
		v.clear();
		v.resize(n + 1);
		low.clear();
		low.resize(n + 1);
		num.clear();
		num.resize(n + 1, -1);
		vis.clear();
		vis.resize(n + 1);

		int c = 1;
		sc.clear();
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			if (ma[a] == 0) {
				mg[c] = a;
				ma[a] = c;
				c++;
			}
			if (ma[b] == 0) {
				mg[c] = b;
				ma[b] = c;
				c++;
			}
			v[ma[a]].push_back(ma[b]);

		}
		printf("Calling circles for data set %d:\n", tt++);
		cnt = 1;
		for (int i = 1; i <= n; i++) {
			if (num[i] == -1) {
				calc(i);
			}
		}

		for (int i = sc.size() - 1; i >= 0; i--) {
			cout << mg[sc[i][sc[i].size() - 1]];
			for (int j = sc[i].size() - 2; j >= 0; j--) {
				cout << ", " << mg[sc[i][j]];
			}
			puts("");
		}

	}
	return 0;

}


