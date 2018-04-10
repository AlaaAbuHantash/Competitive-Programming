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
/*  You got a dream, you gotta protect it.*/
using namespace std;
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int t, n;
long long c, a, b, cc;
#define mp make_pair
int main() {
	//freopen("test.txt", "rt", stdin);

	scanf("%d", &t);
	string s;
	while (t--) {
		vector<pair<long long, long long> > v;
		scanf("%d%lld", &n, &cc);
		s = "";
		for (int i = 0; i < n; i++) {
			scanf("%lld%lld", &a, &b);
			v.push_back(mp(a, b));
			s += char('0' + i);
		}

		int res = 0, r = 0;
		do {

			c = cc;
			r = 0;
			for (int i = 0; i < n; i++) {
				int cur = s[i] - '0';
				if (c >= v[cur].first) {
					c = c - v[cur].first + v[cur].second;
					r++;
				} else
					break;
			}
			res = max(r, res);
		} while (next_permutation(s.begin(), s.end()));
		printf("%d\n", res);
	}
	return 0;
}

