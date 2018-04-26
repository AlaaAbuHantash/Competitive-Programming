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
int a[1000005];
int main() {
	//freopen("A.txt", "rt", stdin);
	int n, x;
	bool f = 0;
	while (scanf("%d", &n) > 0) {
		if (!n)
			break;
		if (f)
			puts("");
		f = 1;
		memset(a, 0, sizeof(a));
		queue<int> v;
		int m = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			if (a[x] == 0)
				v.push(x);
			a[x]++;
			m = max(a[x], m);
		}
		printf("%d\n", m);
		vector<vector<int> > res(m);

		while (v.size()) {
			x = v.front();
			for (int i = 0; i < m; ++i) {
				res[i].push_back(x);
				a[x]--;
				if (a[x] == 0) {
					v.pop();
					if (v.size() == 0)
						break;
					x = v.front();
				}

			}

		}
		for (int i = 0; i < m; i++) {
			printf("%d", res[i][0]);
			for (int j = 1; j < res[i].size(); j++)
				printf(" %d", res[i][j]);
			puts("");
		}
	}
	return 0;
}

