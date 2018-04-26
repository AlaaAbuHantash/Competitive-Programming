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
int main() {
	//freopen("A.txt", "rt", stdin);
	int x, n, pre;
	while (scanf("%d", &n) > 0) {
		if (!n)
			break;
		scanf("%d", &x);
		pre = x;
		bool f = 0, ff;
		int res = 0, b = x;
		vector<int> r(n+1);

		for (int i = 1; i < n; i++) {
			scanf("%d", &x);
			if (x > pre)
				r[i] = 1;
			pre = x;
		}
		if (b > pre)
			r[0] = 1;
		r[n] = r[0];

		for (int i = 0; i < n; i++) {
			if(r[i] != r[i+1])
				res++;

		}
		printf("%d\n", res);
	}
	return 0;
}

