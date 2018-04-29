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
	//freopen("input", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);

	int a, b;
	cin >> a >> b;
	bool f;
	a++;
	for (int i = a; i < 51; i++) {
		f = 1;
		for (int j = 2; j < i; j++)
			if (i % j == 0)
				f = 0;
		if (f) {
			if (b == i)
				puts("YES");
			else
				puts("NO");
			return 0 ;
		}
	}
	puts("NO");
	return 0;
}

