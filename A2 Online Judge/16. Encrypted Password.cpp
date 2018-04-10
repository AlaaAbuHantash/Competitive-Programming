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

int main() {
	//freopen("input", "rt", stdin);
	int t;
	string a, b;

	cin >> t;
	while (t--) {
		vector<int> v(33);
		cin >> a >> b;
		bool f = 0;
		for (int i = 0; i < b.size(); i++) {
			v[b[i] - 'a']++;
		}
		int r = 0, st = 0;
		for (int i = 0; i < a.size() && !f; i++) {
			if (r == b.size())
				f = 1;
			if (r == 0)
				st = i;
			if (v[a[i] - 'a']) {
				r++;
				v[a[i] - 'a']--;
			} else {
				bool g = 0;
				//cout << "st " << st << " " << a[i] << " " << i << endl;
				for (int j = st; j < i; j++) {
					if (a[i] == a[j]) {
						st = j + 1;
						g = 1;
						break;
					} else {
						v[a[j] - 'a']++;
						r--;
					}

				}
				if (!g) {
					st = i;
				}

			}
		}
		if (r == b.size())
			f = 1;
		if (f)
			puts("YES");
		else
			puts("NO");
	}


	return 0;
}

