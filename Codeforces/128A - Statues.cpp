#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
using namespace std;
#define mp make_pair
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

vector<string> v, tmp;
int vis[9][9];
int z;
void bfs() {
	queue<pair<int, int> > q;
	q.push(mp(7, 0));
	bool f = 0;
	while (!q.empty() && !f) {
		int siz = q.size();
		while (siz-- && !f) {
			int x = q.front().first;
			int y = q.front().second;

			q.pop();
			if (x == 0 && y == 7) {
				f = 1;
			}
			if (v[x][y] == 'S')
				continue;

			q.push(mp(x, y));
			vis[x][y] = 1;
			for (int i = 0; i < 8; i++) {
				int nx = dx[i] + x;
				int ny = dy[i] + y;
				if (nx >= 0 && ny >= 0 && nx < 8 && ny < 8) {
					if (!vis[nx][ny] && v[nx][ny] != 'S')
						q.push(mp(nx, ny));
				}

			}
		}
		tmp.clear();
		tmp.push_back("........");
		for (int i = 0; i < 7; i++) {
			tmp.push_back(v[i]);
		}
		v = tmp;
	}
	if (f)
		puts("WIN");
	else
		puts("LOSE");
}
int main() {
	//freopen("input", "rt", stdin);
	string s;
	for (int i = 0; i < 8; i++) {
		cin >> s;
		v.push_back(s);
	}
	bfs();
	return 0;
}

