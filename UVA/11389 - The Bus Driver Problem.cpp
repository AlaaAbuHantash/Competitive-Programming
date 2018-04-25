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
//#define eps 1e-9
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int main() {
	//freopen("test.txt", "rt", stdin);
	int n, d, r, a[111], b[111];
	while (scanf("%d%d%d", &n, &d, &r) > 0) {
		if (n + d + r == 0)
			return 0;
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);

		for (int i = 0; i < n; ++i)
			scanf("%d", &b[i]);

		sort(a, a + n);
		sort(b, b + n);
		int res = 0;
		for (int i = 0, j = n - 1; i < n; ++i, --j) {
			if (a[i] + b[j] > d)
				res += (a[i] + b[j]) - d;

		}
		printf("%d\n", res * r);
	}

	return 0;

}

