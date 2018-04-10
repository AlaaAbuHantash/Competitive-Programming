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
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
#define mp make_pair
#include<iostream>
using namespace std;

int gcd(int a, int b) {
	if (a % b == 0)
		return b;
	return gcd(b, a % b);

}
int main() {
	//freopen("input", "rt", stdin);
	int t, n, a, b;

	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &a, &b);
		printf("%d %d %d\n", n, a, b);
		n--;
		int res = (n / a) + (n / b);
		int c = gcd(a, b);
		int lcm = a * b / c;
		res -= (n / lcm);

		printf("%d\n", res);

	}
	return 0;
}

