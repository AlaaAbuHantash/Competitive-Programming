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
bool vis[100005];
vector<vector<int > > v;
bool f;
vector<int > r; 
int n; 
void dfs(int x){

	if (x == r[1])
		f = 1; 
	if (vis[x])
		return; 
	vis[x] = 1;
	for (int i = 0; i < v[x].size(); i++)
		if (!vis[v[x][i]])
			dfs(v[x][i]);

}
void dfs2(int x , int rr ){

	if (rr == n)
		f = 1;
	if (vis[x])
		return;
	vis[x] = 1;
	for (int i = 0; i < v[x].size(); i++)
		if (!vis[v[x][i]])
			dfs2(v[x][i],rr+1);

}
int main() {
	//freopen("text.txt", "rt", stdin);

	int m,a,b; 
	cin >> n >> m;
	 v.resize(n+1);
	for (int i = 0; i < m; i++){
		cin >> a >> b; 
		v[a].push_back(b);

		v[b].push_back(a);
	}
	f = 0;
	 a = 0, b = 0; 
	for (int i = 1; i <= n; i++){
		if (v[i].size() == n - 1)
			f = 1;
		if (v[i].size() == 2)
			a++;
		else if (v[i].size() == 1){
			b++;
			r.push_back(i);
		}
	}


	if (f && b==n-1)
		puts("star topology");
	else {
		f = 0;
		if (b == 2 && a == n - 2){
			dfs(r[0]);
			if (f)
				puts("bus topology");
			
		}
		else if (a == n){
			dfs2(1,1);
			if (f)
				puts("ring topology");
		}

		if (!f)
			puts("unknown topology");

			
	}
	return 0;
}