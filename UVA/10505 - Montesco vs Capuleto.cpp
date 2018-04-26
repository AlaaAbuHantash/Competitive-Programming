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
#define mp make_pair
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int n, x, k, a, b;
int vis[222];
vector<vector<int> > v;
bool f;
void dfs(int node) {

	for (int i = 0; i < v[node].size(); ++i) {
		if (vis[v[node][i]] == -1) {
			vis[v[node][i]] = 1 - vis[node];
			if (vis[v[node][i]] == 0)
				a++;
			else
				b++;
			dfs(v[node][i]);
		} else if (vis[v[node][i]] == vis[node]) {
			f = 0;
		}
	}
}
int main() {

//freopen("input.in" , "rt" , stdin);
//freopen ("myfile.txt","w",stdout);

	int t;
	scanf("%d", &t);
	while (t--) {

		scanf("%d", &n);
		v.clear();
		v.resize(202);

		memset(vis, -1, sizeof(vis));
		for (int i = 0; i < n; i++) {
			scanf("%d", &k);
			for (int j = 0; j < k; j++) {
				scanf("%d", &x);
				if (x > n)
					continue;
				v[i].push_back(x - 1);
				v[x - 1].push_back(i);
				//r = max(r, x);
			}

		}

		int res = 0;
		for (int i = 0; i < n; ++i) {
			if (vis[i] == -1) {
				vis[i] = 0;
				a = 1, b = 0, f = 1;
				dfs(i);
				if (f) {
					res += max(a, b);
				}

			}
		}
		printf("%d\n", res);
	}
	return 0;
}


