#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<set>
using namespace std;
#define eps 1e-9
#define mp make_pair
int dx[] = { -1, 0, 0, 1, 1, 1, -1, -1 };
int dy[] = { 0, -1, 1, 0, 1, -1, 1, -1 };
int vis[11][11];
int main() {
	//freopen("input", "rt", stdin);
	int n, m;
	cin >> n >> m;
	string s;
	vector<string> v;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			bool f = 0;
			if (v[i][j] == 'W') {
				for (int k = 0; k < 4 && !f; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx >= 0 && ny >= 0 && nx< n && ny < m) {
						if (!vis[nx][ny] && v[nx][ny] == 'P') {
							res++;
							f = 1;
							vis[nx][ny] = 1;
						}
					}
				}
			}
		}
	}
	printf("%d\n", res);
	return 0;
}

