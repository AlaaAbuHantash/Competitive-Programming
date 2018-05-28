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
string a, b;
int lena, lenb;
int main() {
	//freopen("test.txt", "rt", stdin);
	cin >> a >> b;
	lena = a.length();
	lenb = b.length();
	int res = -1;

	for (int i = 0; i < lenb + 1; ++i)
		a = "#" + a;

	lena = a.length();
	for (int i = 0; i < lena; ++i) {
		int c = 0;
		for (int j = 0; j < lenb; ++j) {
			if (i + j > lena) {
				c += lenb - j;
				break;
			}
			if (a[i + j] != b[j])
				c++;

		}
		if (res == -1 || res > c)
			res = c;
	}
	printf("%d\n", res);
	return 0;
}

