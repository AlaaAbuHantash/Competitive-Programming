#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
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
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int a[1005][1005];
int n, m, xx, yy;
int check(int x, int y) {
	int f = 1, ff = 1, fff = 1, ffff = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			if (!(i + x <= n && j + y <= n && a[i + x][j + y] && f))
				f = 0;
			if (!(i + x <= n && y - j >= 1 && a[i + x][y - j] && ff))
				ff = 0;
			if (!(x - i >= 1 && y - j >= 1 && a[x - i][y - j] && fff))
				fff = 0;
			if (!(x - i >= 1 && y + j <= n && a[x - i][j + y] && ffff))
				ffff = 0;
		}
	if (f + ff + fff + ffff >= 1)
		return 1;
	return 0;

}
int main() {

	//freopen("a.txt", "rt", stdin);

	cin >> n >> m;
	int res = -1, c = 0;
	for (int i = 0; i < m; i++) {
		cin >> xx >> yy;
		a[xx][yy] = 1;
		c++;
		if (c <= 8)
			continue;
		bool r = check(xx, yy) || check(xx - 1, yy - 1) || check(xx, yy - 1)
				|| check(xx - 1, yy);
		if (r && res == -1) {
			//cout << xx << " " << yy << endl;
			res = i + 1;
		}
	}
	cout << res << endl;

	return 0;
}

