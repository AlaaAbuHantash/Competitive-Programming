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
#include <stdio.h>
#include <fstream>
#define mp make_pair
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
const int N = 1e5;
int a[N + 10], c[N + 10];
map<pair<int, int>, bool> ma;
int main() {

	//freopen("b.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m, x, y, res = 0, col = 0;
	cin >> n >> m;

	//vector<set<int> > v(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i + 1];
		if (col == 0 || col > a[i + 1])
			col = a[i + 1];
	}
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		if (!ma[mp(a[y], a[x])] && a[x] != a[y])
			c[a[x]]++;
		ma[mp(a[y], a[x])] = 1;
		if (!ma[mp(a[x], a[y])] && a[x] != a[y])
			c[a[y]]++;
		ma[mp(a[x], a[y])] = 1;

		if (c[a[y]] > res) {
			res = c[a[y]];
			col = a[y];
		} else if (c[a[y]] == res) {
			col = min(col, a[y]);
		}
		if (c[a[x]] > res) {
			res = c[a[x]];
			col = a[x];
		} else if (c[a[x]] == res) {
			col = min(col, a[x]);
		}

	}
	cout << col << endl;
	return 0;
}

