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
#define mp make_pair
#define eps 1e-6
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
map<pair<int , int > , int > path;
int vis[111][100005];
const int M = 10001;
int main() {
	//freopen("text.txt", "rt", stdin);

	int n, l, st;
	cin >> n >> st >> l;
	queue<int > q;
	q.push(st);
	bool f = 0;
	int lev = 1;
	while (!q.empty()) {
		int siz = q.size();
		int fr = q.front();
		if (lev == n && (fr <= 0 || fr > l)){ q.pop(); continue; }
		if (lev == n){
			f = 1;
			//break;
			vector<int > res; 
			res.push_back(fr);
			int xx = fr;
			for (int i = n-1; i >= 1; i--){ 
				int tmp =  path[mp(i, fr)];
				res.push_back(tmp);
				fr =  tmp-fr;
			}
			for (int i = res.size() - 1; i >= 0; i--)
				printf("%d ",res[i]);
			return 0; 
		}
		while (siz--){
			int fr = q.front();

			q.pop();
			for (int i = 1; i <= l; i++){

				if (!vis[lev][i - fr+M]){
					q.push(i - fr);
					vis[lev][i - fr + M] = 1;
					path[mp(lev, i-fr)] = i; 
				}
			}
		}

		lev++;

	}

	if (!f)
		puts("-1");

	return 0;
}

