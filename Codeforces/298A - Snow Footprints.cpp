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
#define pb push_back
#define mp make_pair
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int main() {
	//freopen("input", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);
	int n;
	string s;
	cin >> n >> s;
	bool f = 0;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == 'R' && s[i + 1] == 'L') {
			cout << i + 1 << " " << i + 2 << endl;
			f = 1;
			break;
		}
	}

	int x = -1, y = n + 2;
	if (!f)
		for (int i = 0; i < n; i++) {
			if (s[i] == 'R') {
				x = max(x, i);
				y = min(y, i);

			}
		}
	if (x != -1 && y != n + 2) {
		cout << y + 1 << " " << x + 2<< endl;
		f = 1;
	}	
	x = -1, y = n + 2;
	if (!f)
		for (int i = 0; i < n; i++) {
			if (s[i] == 'L') {
				x = max(x, i);
				y = min(y, i);
			}
		}
	if (x != -1 && y != n + 2) {
		cout << y + 1 << " " << y<< endl;
		f = 1;
	}

	if ( !f )
		cout << "1 1\n";
	return 0;
}

