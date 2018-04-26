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
int vis[33][33];
int main() {
	//freopen("A.txt", "rt", stdin);
	string s;
	while (cin >> s) {
		int len = s.length();

		int c = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i < len - 1; i++) {
			if (s[i - 1] == s[i + 1] && !vis[s[i - 1] - 'A'][s[i] - 'A']) {
				vis[s[i - 1] - 'A'][s[i] - 'A'] = 1;
				c++;
			}
			if (c >= 2)
				break;
		}
		if (c >= 2)
			cout << s << endl;
		else {
			//memset(vis, 0, sizeof(vis));
			for (int i = 1; i < len - 2; i++) {
				if (s[i] == s[i + 1] && s[i - 1] == s[i + 2]
						&& !vis[s[i - 1] - 'A'][s[i] - 'A']) {
					vis[s[i - 1] - 'A'][s[i] - 'A'] = 1;
					c++;
				}
				if (c >= 2)
					break;

			}
			if (c >= 2)
				cout << s << endl;
		}
	}

	return 0;
}

