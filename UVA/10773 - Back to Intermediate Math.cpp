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
	//freopen("test.txt", "rt", stdin);
	double d, u, v;
	int t, tt = 1;
	scanf("%d", &t);
	while (t--) {
		// d  v u
		scanf("%lf%lf%lf", &d, &v, &u);
		if (u == 0 || v == 0) {
			printf("Case %d: can't determine\n", tt++);
			//	puts("");
			continue;
		}
		double aa = (double) d / (double) u;
		double bb = (u * u) - (v * v);
		if (bb <= 0) {
			printf("Case %d: can't determine\n", tt++);
			//puts("can’t determine");
		} else {
			double s = d / sqrt(bb);
			printf("Case %d: %.3lf\n", tt++, fabs(aa - s));

		}
	}
	return 0;
}

