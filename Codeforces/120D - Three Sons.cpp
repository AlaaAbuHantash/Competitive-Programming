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
using namespace std;
#define mp make_pair
#define eps 1e-6
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int aa[3], bb[3];
int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "w", stdout);
	int n, m, x;
	cin >> n >> m;
	vector<int> r, c(m);
	int all = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++) {
			cin >> x;
			sum += x;
			c[j] += x;
			all += x;
		}
		r.push_back(sum);
	}

	cin >> aa[0] >> aa[1] >> aa[2];
	sort(aa, aa + 3);
	x = 0;
	int res = 0;
	for (int i = 0; i < n - 2; i++) {
		x += r[i];
		int y = 0;
		for (int j = i + 1; j < n - 1; j++) {
			y += r[j];
			int z = all - y - x;
			bb[0] = x, bb[1] = y, bb[2] = z;
			sort(bb, bb + 3);
			if (aa[0] == bb[0] && aa[1] == bb[1] && aa[2] == bb[2])
				res++;
		}

	}

	x = 0;
	for (int i = 0; i < m - 2; i++) {
		x += c[i];
		int y = 0;

		for (int j = i + 1; j < m - 1; j++) {
			y += c[j];
			int z = all - y - x;
			bb[0] = x, bb[1] = y, bb[2] = z;
			sort(bb, bb + 3);
			if (aa[0] == bb[0] && aa[1] == bb[1] && aa[2] == bb[2])
				res++;
		}

	}
	cout << res << endl;
	return 0;
}

