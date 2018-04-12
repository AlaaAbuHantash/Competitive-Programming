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
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int a[11][11];
class LightedPanels {
public:
	int n, m;
	bool f;
	int minTouch(vector<string> board) {
		f = 0;
		n = board.size();
		m = board[0].size();
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (board[i][j] == '*')
					a[i][j] = 1;
		int rr = calc(0, 0);

		if (f)
			return rr;

		return -1;

	}
	int calc(int r, int c) {

		if (r >= 3) {

			for (int i = r - 3; i < r - 1; i++)
				for (int j = 0; j < m; j++)
					if (a[i][j] == 0)
						return 2e9;
		}
		if (r == n) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					if (a[i][j] == 0)
						return 2e9;
			f = 1;
			return 0;
		}
		if (c == m)
			return calc(r + 1, 0);

		int res = 2e9;
		res = min(res, calc(r, c + 1));
		a[r][c] = !a[r][c];
		for (int i = 0; i < 8; i++) {
			int nx = r + dx[i];
			int ny = c + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				a[nx][ny] = !a[nx][ny];
			}
		}
		res = min(res, calc(r, c + 1) + 1);
		a[r][c] = !a[r][c];
		for (int i = 0; i < 8; i++) {
			int nx = r + dx[i];
			int ny = c + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				a[nx][ny] = !a[nx][ny];
			}
		}

		return res;
	}

};
