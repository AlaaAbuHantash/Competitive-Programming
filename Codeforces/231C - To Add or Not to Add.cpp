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
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int n, x, k;
map<long long, int> c;
int main() {
	//freopen("test.txt", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);
	scanf("%d%d", &n, &k);
	vector<int> v;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x);
		v.push_back(x);
	}
	sort(v.rbegin(), v.rend());
	c[0] = 0;
	for (int i = 0; i < n; ++i) {
		c[i + 1] = c[i] + v[i];
		//cout << c[i + 1] << " " << 1 + i << endl;
	}
	int vv;
	int mx = 0, res = 0, kk = k, val = -1;
	for (int i = 0; i < n; i++) {
		if (val == -1) {
			val = i;
			res++;
			if (res >= mx) {
				mx = res;
				vv = val;
			}
		} else if (v[val] - v[i] <= kk) {
			kk -= v[val] - v[i];
			res++;
			//cout << v[val] << " " << v[i] << " " << kk << " " << res << endl;
			if (res >= mx) {
				mx = res;
				vv = val;
			}

		} else {
			i--;
			int pr = val;
			while (val <= i && v[val] == v[pr]) {
				res--;
				val++;
			}
			long long no = (v[val] * (i - val + 1)) - (c[i + 1] - c[val]);
			kk = k - no;

			if (kk >= 0 && res >= mx) {
				mx = res;
				vv = val;
			}
		}
	}
	printf("%d %d\n", mx, v[vv]);

	return 0;
}

