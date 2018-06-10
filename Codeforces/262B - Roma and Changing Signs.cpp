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
#define mp make_pair
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int main() {
	//freopen("input", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);
	int n, k, x, a;
	cin >> n >> k;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	long long sum = 0;
	for (int i = 0; i < n; i++)
		if (k) {
			if (v[i] < 0 && k) {
				v[i] *= -1;
				sum += v[i];
				k--;
			} else if (v[i] == 0) {
				k = 0;
			} else if (v[i] > 0) {
				if (i - 1 >= 0) {
					a = min(v[i - 1] * -1, v[i]);
					if (v[i - 1]  < v[i]) {
						if (k % 2)
							sum -= 2 * v[i - 1];
						sum += v[i];
					} else {
						if (k % 2)
							sum -= v[i];
						else
							sum += v[i];
					}
					k = 0;
				} else {
					a = v[i];
					if (k % 2)
						sum -= a;
					else
						sum += a;
				}
				k = 0;

			}
		} else
			sum += v[i];

	if (k % 2)
		sum -= 2 * v[n - 1];

	cout << sum << endl;
	return 0;
}
