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
map < int, int > m; 
int c;
int vis[4005];
int adj[4005][4005];
int main() {
	//freopen("test.txt", "rt", stdin);
	int n, m, a , b; 
	cin >> n >> m;
	
	vector<vector<int > > v(n + 1); 
	vector<pair < int, pair < int, int > > >  p;
	for (int i = 0; i < m; i++){
		cin >> a >> b; 

		v[a].push_back(b);
		v[b].push_back(a);
		adj[a][b] = 1; 
		adj[b][a] = 1;
		if (vis[a] && vis[b]){

			for (int j = 0; j < v[a].size(); j++){
				if (adj[v[a][j]][b]){
					p.push_back(mp(a, mp(b, v[a][j])));
					//cout << a << " " << b << " " << v[a][j] << endl;
				}
			}
		}
		vis[a] = 1; 
		vis[b] = 1; 

	}

	int res = -1;
	for (int i = 0; i < p.size(); i++){
		int aa = p[i].first; 
		int bb = p[i].second.first; 
		int cc = p[i].second.second;
		int x = v[aa].size() + v[bb].size() + v[cc].size() - 6; 
		
		if (res == -1 || x < res)
			res = x;
	}
	cout << res << "\n";
}

