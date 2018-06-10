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
/*YOU got a DREAM, YOU gotta protect it. */
#define pb push_back
#define mp make_pair
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int vis[55];
int main() {
	//freopen("input", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);
	int n, m, k, x;

	cin >> n >> m >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.rbegin(), v.rend());
	int res = 0, f = 0;
	for (int i = 0; i < n && !f; i++) {
		if (k >= m) {
			f = 1;
			break;
		}
		if (!vis[i] && k >= 1) {
			k--;
			m = m - v[i];
			res++;
		}
		vis[i] = 1;
		for (int j = 0; j < v[i] && !f; j++) {
			if (k >= m)
				f = 1;
			for (int g = 0; g < n && !f; g++) {
				if (!vis[g] && v[g] != 1) {
					m = m - v[g] + 1;
					res++;
					vis[g] = 1;
					break;
				}

			}

		}
	}
	if (f)
		printf("%d\n", res);
	else
		puts("-1");
	return 0;
}

