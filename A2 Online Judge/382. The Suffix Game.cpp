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
int main() {
	//freopen("test.txt", "rt", stdin);
	int t, tt = 1;
	string a, b, ta, tb;
	scanf("%d", &t);
	bool f = 0;
	while (t--) {
		cin >> a >> b;
		ta = a;
		tb = b;
		if (f)
			puts("");
		f = 1;
		printf("Game #%d:\n", tt++);
		for (int i = a.length() - 1, j = b.length() - 1; i > 0 && j > 0;
				i--, j--)
			if (a[i] == b[j]) {
				ta.erase(i, 1);
				tb.erase(j, 1);
			} else
				break;

		cout << "   The input words are " << a << " and " << b << ".\n";
		cout << "   The words entered in the notebook are " << ta << " and "
				<< tb << ".\n";
	}
	return 0;

}

