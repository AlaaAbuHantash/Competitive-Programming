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
	int c, s, tt = 1;
	int a[20], b[22], cc[22];
	while (scanf("%d%d", &c, &s) > 0) {
		for (int i = 0; i < 12; ++i)
			a[i] = b[i] = cc[i] = 0;
		int sum = 0;
		for (int i = 0; i < s; ++i) {
			scanf("%d", &a[i]);
			b[i] = a[i];
			sum += a[i];
		}
		int n = 2 * c;
		sort(a, a + n);
		double g = sum / (double) c, res = 0, r = 0;
		printf("Set #%d\n", tt++);
		for (int i = 0; i < c; i++) {

			int x = a[i], y = a[n - i - 1];
			bool ff = 0, f = 0;
			r = a[i] + a[n - i - 1];
			for (int j = 0; j < s; j++) {
				if (b[j] == x && x != 0 && !ff && !cc[j]) {
					cc[j] = i + 1;
					ff = 1;
					//printf(" %d", x);
				} else if (b[j] == y && y != 0 && !f && !cc[j]) {
					f = 1;
					cc[j] = i + 1;
					//printf(" %d", y);
				}
			}
			//cout << "R " <<r  << " " << g << endl;
			res += fabs(g - r);

		}
		vector<vector<int> > v(c);
		int k = 0;
		for (int i = 0; i < s; ++i) {
			if (!b[i])
				continue;
			v[k].push_back(b[i]);

			for (int j = i + 1; j < s; ++j) {

				if (cc[i] == cc[j] && b[j]) {
					v[k].push_back(b[j]);

					b[j] = 0;
				}
			}

			k++;
		}
		for (int i = 0; i < c; i++) {
			printf(" %d:", i);
			for (int j = 0; j < v[i].size(); j++)
				printf(" %d", v[i][j]);
			puts("");

		}

		printf("IMBALANCE = %.5lf\n\n", res);
	}

	return 0;

}

