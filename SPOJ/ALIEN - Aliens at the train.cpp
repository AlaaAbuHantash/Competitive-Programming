#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
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
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
long long a[1000005];
int main() {
	//freopen("a.txt", "rt", stdin);
	long long n, m;
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%lld%lld", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%lld", &a[i]);
		long long cur = 0;
		long long sum = 0;
		int ind = 0;
		long long c = 0;
		long long res = 0;
		for (int i = 0; i < n; i++) {
			if (cur + a[i] <= m) {
				cur += a[i];
				c++;
			} else {
				cur += a[i];
				c++;
				while (ind < n && cur > m) {
					cur -= a[ind];
					ind++;
					c--;
				}
			}
			if (c > res) {
				res = c;
				sum = cur;
			} else if (c == res && cur < sum)
				sum = cur;

		}
		printf("%lld %lld\n", sum, res);

	}
	return 0;
}

