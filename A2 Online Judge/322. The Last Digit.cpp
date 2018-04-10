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
int main() {
	int arr[] = { 1, 4, 9, 6, 5, 6, 9, 4, 1, 0 };
	//freopen("test.txt", "rt", stdin);
	int t, tt = 1;
	unsigned long long a, b;
	scanf("%d", &t);
	while (t--) {
		cin >> a >> b;
		a--;
		unsigned long long res = 0, res2 = 0;
		unsigned long long c, z;
		c = (unsigned long long) (a / (unsigned long long) 10);
		if (c % 2)
			res = res + (unsigned long long) 5;
		z = a % 10;
		while (z != 0) {
			res += (unsigned long long) arr[z - 1];
			z--;
		}
		c = (unsigned long long) (b / (unsigned long long) 10);
		if (c % 2)
			res2 = (unsigned long long) 5;

		z = b % 10;
		while (z != 0) {
			res2 += (unsigned long long) arr[z - 1];
			z--;
		}

		res2 = res2 % 10;
		res = res % 10;
		int ala = res2 - res;

		ala = (ala % 10 + 10) % 10;

		printf("Case %d: ", tt++);
		cout << ala << endl;
	}

	return 0;
}

