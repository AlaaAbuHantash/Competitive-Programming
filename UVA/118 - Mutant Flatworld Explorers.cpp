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
using namespace std;
int dx[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
int dy[] = { 0, 1, 0, -1, -1, -1, 1, 1 };
#define mp make_pair
int n, m, x, y;
char c;
string s;
char arr[] = { 'N', 'E', 'S', 'W' };
map<pair<int, int>, int> a;
void calc(int ind, int dir, int xx, int yy) {
	//cout << ind << " " << dir << " " << xx << " " << yy << endl;

	if (ind == s.length()) {
		printf("%d %d %c\n", xx, yy, arr[dir]);
		return;
	}
	if (s[ind] == 'R')
		calc(ind + 1, (dir + 1) % 4, xx, yy);
	else if (s[ind] == 'L') {
		if (dir - 1 == -1)
			calc(ind + 1, 3, xx, yy);
		else
			calc(ind + 1, (dir - 1) % 4, xx, yy);
	} else if (s[ind] == 'F') {
		if (dir == 1) {
			if (xx + 1 > n && a[mp(xx, yy)] == 0) {
				a[mp(xx, yy)] = 1;
				printf("%d %d %c LOST\n", xx, yy, arr[dir]);
				return;
			} else if (xx + 1 > n) {
				calc(ind + 1, dir, xx, yy);
				return;
			}
			calc(ind + 1, dir, xx + 1, yy);
		} else if (dir == 0) {
			if (yy + 1 > m && a[mp(xx, yy)] == 0) {
				a[mp(xx, yy)] = 1;
				printf("%d %d %c LOST\n", xx, yy, arr[dir]);
				return;
			} else if (yy + 1 > m) {
				calc(ind + 1, dir, xx, yy);
				return;
			}
			calc(ind + 1, dir, xx, yy + 1);
		} else if (dir == 3) {
			if (xx - 1 < 0 && a[mp(xx, yy)] == 0) {
				a[mp(xx, yy)] = 1;
				printf("%d %d %c LOST\n", xx, yy, arr[dir]);
				return;
			} else if (xx - 1 < 0) {
				calc(ind + 1, dir, xx, yy);
				return;
			}
			calc(ind + 1, dir, xx - 1, yy);
		} else if (dir == 2) {
			if (yy - 1 < 0 && a[mp(xx, yy)] == 0) {
				a[mp(xx, yy)] = 1;
				printf("%d %d %c LOST\n", xx, yy, arr[dir]);
				return;
			} else if (yy - 1 < 0) {
				calc(ind + 1, dir, xx, yy);
				return;
			}
			calc(ind + 1, dir, xx, yy - 1);
		}
	}

}
int main() {
	//freopen("test.txt", "rt", stdin);
	scanf("%d%d", &n, &m);
	//	swap(n, m);

	while (scanf("%d%d %c", &x, &y, &c) > 0) {
		//cout << x << " " << y << " " << c << endl;
		cin >> s;
		if (c == 'N') {
			calc(0, 0, x, y);
		} else if (c == 'S') {
			calc(0, 2, x, y);
		} else if (c == 'E') {
			calc(0, 1, x, y);
		} else if (c == 'W') {
			calc(0, 3, x, y);
		}
	}
	return 0;
}


