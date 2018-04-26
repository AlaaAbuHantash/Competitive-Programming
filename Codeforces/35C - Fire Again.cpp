#define _CRT_SECURE_NO_WARNINGS
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
#include <stdio.h>
#include <fstream>
#define mp make_pair
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int vis[2005][2005];
int main() {
	
	freopen("input.txt" , "rt" , stdin);
	freopen ("output.txt","w",stdout);
	int n, m, k, x, y;
	cin >> n >> m >> k; 
	queue<pair < int, int >  > q;
	for (int i = 0; i < k; i++){
		cin >> x >> y; 
		q.push(mp(x, y));
		vis[x][y] = 1;
	}

	while (!q.empty()){
		x = q.front().first; 
		y = q.front().second;
		q.pop();
		for (int i = 0; i <4; i++){
			int nx = x + dx[i]; 
			int ny = y + dy[i]; 
			if (nx >= 1 && ny >= 1 && nx <= n&&ny <= m&&!vis[nx][ny]){
				vis[nx][ny] = 1; 
				q.push(mp(nx, ny));
			}
		}
	}

	cout << x << " " << y << endl;
	return 0;
}
