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
using namespace std;
#define mp make_pair
#define eps 1e-6
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
vector<vector<int > > v;
vector<int >vis;
int st;
bool f;
void dfs(int x){
	if (x == st)
		f = 1;

	if (vis[x])
		return;
	vis[x] = 1;
	dfs(v[x][0]);
}
int main() {
	//freopen("test.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);

	int n, x, a, t;
	cin >> t;
	while (t--){
		cin >> n; 
		v.clear();
		vis.clear();
		v.resize(n);
		vis.resize(n);
		for (int i = 0; i < n; i++){
			cin >> x; 
			v[i].push_back(x-1);
		}
		int c = 0;
		for (int i = 0; i < n; i++)
			if (!vis[i]){
				st = i;
				f = 0;
				dfs(i);
				if (f)c++;
			}
		printf("%d\n", c);
	}

	return 0;
}