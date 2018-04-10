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
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> s;
		bool f = 0;
		int res = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '.') {
				f = 1;
				continue;
			}
			int r = 0;
			if (s[i] >= 'A' && s[i] <= 'Z')
				r = s[i] - 'A' + 1;
			else
				r = s[i] - 'a' + 1;

			if (f)
				res -= r;
			else
				res += r;

		}

		if (res != 0)
			cout << s << endl;

	}

	return 0;
}


