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
	int t, n, x, ff = 0;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (ff)
			puts("");
		ff = 1;
		vector<int> v;
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			v.push_back(x);
		}
		sort(v.begin(), v.end());

		int res = 0;
		vector<pair<int, int> > r;
		deque<int> q;
		for (int i = 0; i < n; i++)
			q.push_back(v[i]);
		int x, y, z, a, b;
		while (1) {
			n = q.size();
			//cout << " n " << n << endl;
			if (n == 1) {
				x = q.front();
				res += x;
				q.pop_front();
				r.push_back(mp(x, -1));
				break;
			} else if (n == 2) {
				x = q.front();
				q.pop_front();
				y = q.front();
				q.pop_front();
				res += y;
				r.push_back(mp(x, y));
				break;
			} else if (n == 3) {
				x = q.front();
				q.pop_front();
				y = q.front();
				q.pop_front();
				z = q.front();
				q.pop_front();
				res += y + x + z;
				r.push_back(mp(x, y));
				r.push_back(mp(x, -1));
				r.push_back(mp(x, z));
				break;

			} else {
				x = q.front();
				q.pop_front();
				y = q.front();
				q.pop_front();
				b = q.back();
				q.pop_back();
				a = q.back();
				q.pop_back();

				if (2 * y + x + b <= 2 * x + a + b) {
					r.push_back(mp(x, y));
					r.push_back(mp(y, -1));
					r.push_back(mp(a, b));
					r.push_back(mp(x, -1));
					q.push_front(y);
					q.push_front(x);
					res += 2 * y + x + b;

				} else {
					r.push_back(mp(x, a));
					r.push_back(mp(x, -1));
					r.push_back(mp(x, b));
					r.push_back(mp(x, -1));
					q.push_front(y);
					q.push_front(x);
					res += 2 * x + a + b;

				}

			}
		}

		printf("%d\n", res);
		for (int i = 0; i < r.size(); ++i) {
			printf("%d", r[i].first);
			if (r[i].second != -1)
				printf(" %d", r[i].second);
			puts("");
		}

	}
	return 0;
}

