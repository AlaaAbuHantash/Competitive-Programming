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
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int main() {
	//freopen("input" , "rt" , stdin);
	//freopen ("myfile.txt","w",stdout);
	int a, b, c, n;
	cin >> n;
	while (n--) {
		int res = 0;
		cin >> a >> b >> c;
		while (1) {
			if (a < 2 || b < 1)
				break;
			a = a - 2;
			b = b - 1;
			if (a + b >= c)
				res++;
			else
				break;
		}
		cout << res << endl;
	}
	return 0;
}

