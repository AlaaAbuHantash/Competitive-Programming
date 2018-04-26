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
int n, a, b,x,y;
int m[22][22], r[3];
int vis[22][22];
int cur,f;
int dfs(int aa, int bb){
	int res = 0; 
	for (int i = 0; i < 4; i++){
		int nx = aa + dx[i]; 
		int ny = bb + dy[i]; 
		if (nx >= 0 && ny >= 0 && nx < n&&ny < n && !vis[nx][ny])
			if (m[nx][ny] == 0){
				vis[nx][ny] = 1;
				res += dfs(nx, ny) + 1;
			}
			else {
				if (cur == -1)
					cur = m[nx][ny];
				else if (cur != m[nx][ny])
					f = 0;
			}

	}
	return res;
}
int main() {
	//freopen("test.txt", "rt", stdin);
	while (cin >> n >> a >> b && n){
		r[1] = r[2] = 0;
		memset(m, 0, sizeof(m));
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < a; i++) {
			cin >> x >> y;
			m[x - 1][y - 1] = 1;
		}
		for (int i = 0; i < b; i++) {
			cin >> x >> y;
			m[x - 1][y - 1] = 2;
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (m[i][j] == 0&& !vis[i][j] ){
					cur = -1;
					f = 1;
					vis[i][j] = 1;
					int xx = dfs(i, j);
		
					if (cur != -1 && f)
						r[cur] += xx+1;
				}

		if (r[1] == r[2])
			puts("Draw");
		else if (r[1]>r[2])
			printf("Black wins by %d\n", r[1] - r[2]);
		else
			printf("White wins by %d\n", r[2] - r[1]);

	}
	return 0;
}