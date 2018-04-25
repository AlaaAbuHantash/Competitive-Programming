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
	int n;
	while (scanf("%d", &n) > 0) {
		if (n < 0)
			return 0;
		int tmp = n;
		int res = -1;
		for (int i = 5; i >= 1; --i) {
			bool f = 1;
			n = tmp;
			int r = 0;
			while (true) {
				if (n == 0 || n % i == 0)
					break;

				int x = n - 1;
				if (x % i || r > n) {
					f = 0;
					break;
				}
				x = x / i;
				n = n - 1 - x;
				r++;
			}
			if (r == i && f) {
				res = i ;
				break;
			}
		}

		if (res == -1)
			printf("%d coconuts, no solution\n", tmp);
		else
			printf("%d coconuts, %d people and 1 monkey\n", tmp, res);
	}
	return 0;
}
