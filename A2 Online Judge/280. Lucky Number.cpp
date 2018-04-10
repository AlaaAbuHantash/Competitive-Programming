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
int t, n, aa, bb;
#define mp make_pair
char a[11], b[11];
int main() {
	//freopen("test.txt", "rt", stdin);

	scanf("%d", &t);
	string s, s2;
	while (t--) {
		s = "";
		s2 = "";
		scanf(" %s %s", a, b);
		int la = strlen(a);
		int lb = strlen(b);
		for (int i = 0; i < la; i++)
			s += char('0' + i);

		for (int i = 0; i < lb; i++)
			s2 += char('0' + i);

		bool f = 0;
		vector<int> v;
		bool gg = 1;
		do {
			bb = 0;
			gg = 1;
			for (int i = 0; i < s2.length() && gg; i++) {
				int cur = s2[i] - '0';
				bb *= 10;
				bb += b[cur] - '0';
				if (i == 0 && !bb) {
					gg = 0;
				}
			}
			if (gg)
				v.push_back(bb);
		} while (next_permutation(s2.begin(), s2.end()));

		do {
			aa = 0;
			gg = 1;
			for (int i = 0; i < s.length() && gg; i++) {
				int cur = s[i] - '0';
				aa *= 10;
				aa += a[cur] - '0';
				if (i == 0 && !aa)
					gg = 0;

			}
			int r = aa;
			if (gg)
				for (int i = 0; i < v.size() && !f; i++) {
					bb = v[i];
					aa = r;
					int c = aa + bb;

					bool g = 0;
					while (c) {
						g = 1;
						aa = c % 10;
						c = c / 10;
						bb = -1;

						if (c) {
							bb = c % 10;
							c = c / 10;
						}

						if (aa != bb) {
							g = 0;
							break;
						}

					}
					if (g)
						f = 1;
				}

		} while (next_permutation(s.begin(), s.end()) && !f);
		if (f)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}

