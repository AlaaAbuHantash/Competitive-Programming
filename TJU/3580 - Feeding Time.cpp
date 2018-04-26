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
int n, m;
vector<string > s;
vector<vector<int > > vis;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int main() {
	//freopen("test.txt", "rt", stdin);

	cin >> m >> n;
	s.clear();
	s.resize(n + 1);
	vis.clear();
	vis.resize(n + 1, vector<int >(m + 1));
	for (int i = 0; i < n; i++)
		cin >> s[i];

	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!vis[i][j] && s[i][j] == '.'){
				int r = 0;
				queue<pair < int, int > > q; 
				q.push(mp(i, j));
				while (!q.empty()){
					int x = q.front().first;
					int y = q.front().second;
					r++;
					q.pop();
					vis[x][y] = 1; 
					for (int i = 0; i < 8; i++){
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (nx >= 0 && ny >= 0 && nx < n && ny < m &&!vis[nx][ny] && s[nx][ny] == '.')
						{
							vis[nx][ny] = 1; 
							q.push(mp(nx, ny));
						}
					}
				}
				res = max(res, r);
			}

	cout << res << endl;

	return 0;
}