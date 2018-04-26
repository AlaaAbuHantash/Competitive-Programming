#define _CRT_SECURE_NO_WARNINGS
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
int t, n;
string s;
vector<vector<int> > v;
int vis[55];
int rr;
int main() {
	//freopen("b.txt", "rt", stdin);

	scanf("%d", &t);
	while (t--) {
		cin >> s;
		int n = s.length();
		v.clear();
		v.resize(n);

		for (int j = 0; j < n; j++)
			if (s[j] == 'Y')
				v[0].push_back(j);
		for (int i = 1; i < n; i++) {
			cin >> s;
			for (int j = 0; j < n; j++) {
				if (s[j] == 'Y') {
					v[i].push_back(j);
				}

			}
		}
		int res = 0, ind = 0;
		for (int i = 0; i < n; i++) {
			rr = 0;

			memset(vis, 0, sizeof(vis));
			vis[i]=1;
			for (int j = 0; j < v[i].size(); j++) {
				vis[v[i][j]] = 1;
			}
			for (int j = 0; j < v[i].size(); j++) {
				int nod = v[i][j];
				for (int k = 0; k < v[nod].size(); k++)
					if (!vis[v[nod][k]]) {
						rr++;
						vis[v[nod][k]] = 1;
					}
			}
			if (rr > res) {
				res = rr;
				ind = i;
			}

		}
		printf("%d %d\n", ind, res);
	}

	return 0;
}

