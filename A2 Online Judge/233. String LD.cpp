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
int n;
string s;
int main() {
	//freopen("test.txt", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);
	while (scanf("%d", &n) > 0 && n != 0) {
		vector<string> v;
		map<string, int> m;
		bool f = 0;
		for (int i = 0; i < n; i++) {
			cin >> s;
			v.push_back(s);
			if (m[s])
				f = 1;
			m[s] = 1;
		}

		int res = 0;

		for (int j = 0; j < 101 && !f; j++) {
			m.clear();
			for (int i = 0; i < n && !f; i++) {
				v[i].erase(0, 1);
				if (m[v[i]] || v[i].size() == 0)
					f = 1;
				m[v[i]] = 1;

			}
			if (!f)
				res++;
		}
		cout << res << endl;

	}

	return 0;
}


