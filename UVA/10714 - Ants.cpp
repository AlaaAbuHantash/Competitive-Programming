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

int main() {

//freopen("input.in" , "rt" , stdin);
//freopen ("myfile.txt","w",stdout);

	int t, l, n, x, a, r1, r2;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &l, &n);
		a = 0;
		r2 = 0;
		r1 = 1000000;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &x);
			int y = min(x, l - x);
			a = max(y, a);
			r1 = min(r1, x);
			r2 = max(r2, x);
		}
		int rr = max(max(l - r1, r1), max(r2, l - r2));
		printf("%d %d\n",a,rr);
	}
	return 0;
}


