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
//	freopen("test.txt", "rt", stdin);
	double l, w;
	int n;
	while (scanf("%d%lf%lf", &n, &l, &w) > 0) {
		vector<pair<double, double> > p;
		double r, x;
		for (int i = 0; i < n; ++i) {
			scanf("%lf%lf", &x, &r);

			r = (r * r) - (w / 2.0 * w / 2.0);
			if (r >= 0.0) {
				r = sqrt(r);
				p.push_back(mp(x - r, x + r));
			}
			//cout << x-r << " " << x+r << endl;

		}

		sort(p.begin(), p.end());
		n = p.size();
		double beg = 0;
		bool f = 1;
		int res = 0;
		for (int i = 0; i < n && f; ++i) {

			double mx = -1;
			//cout << beg << " " << l << endl;
			if (beg >= l)
				break;
			bool g = 0;
			while (i < n && p[i].first <= beg) {
				if (mx == -1 || mx < p[i].second) {
					mx = p[i].second;
					g = 1;
				}

				++i;
			}
			//cout << mx << endl;
			--i;
			if (!g)
				f = 0;
			beg = mx;
			res++;
		}
		//cout << beg << " " << res << endl;
		if (f && beg >= l)
			printf("%d\n", res);
		else
			puts("-1");
	}

	return 0;

}
