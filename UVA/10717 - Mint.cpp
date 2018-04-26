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
	int n, t, x;
	while (scanf("%d%d", &n, &t) > 0) {
		if (n + t == 0)
			return 0;
		vector<int> v;
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			v.push_back(x);
		}
		sort(v.begin(), v.end());

		int a = -1, b = -1;
		for (int r = 0; r < t; r++) {
			scanf("%d", &x);
			a = -1, b = -1;
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					for (int k = j + 1; k < n; k++) {
						for (int g = k + 1; g < n; g++) {
							int lcm = v[i];
							lcm = lcm * v[j] / __gcd(lcm, v[j]);
							lcm = lcm * v[g] / __gcd(lcm, v[g]);
							lcm = lcm * v[k] / __gcd(lcm, v[k]);
							//cout << lcm << " " << x << endl;
							if (lcm <= x) {
								int aa = x / lcm;
								//cout << aa << " " << x << " " << lcm << endl;
								if (lcm * aa == x) {
									a = x;
									b = x;
								} else {
									int nub = aa * lcm;
									if (nub <= x
											&& (a == -1
													|| abs(nub - x) < abs(x - a)))
										a = nub;
									aa++;
									nub = aa * lcm;
									if (nub >= x
											&& (b == -1
													|| abs(nub - x) < abs(b - x)))
										b = nub;
								}

							} else {
								int nub = lcm;
								if (nub >= x
										&& (b == -1 || abs(nub - x) < abs(x - b)))
									b = nub;
							}

						}
					}
				}
			}
			if (a == -1)
				a = 0;
			if (b == -1)
				b = 0;
			printf("%d %d\n", a, b);
		}

	}
	return 0;
}

