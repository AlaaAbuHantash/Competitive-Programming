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
int vis[2001];
int c[2001];
int v[2001][2001];
int main() {
	int t; 
	cin >> t; 
	while (t--){
		memset(vis, 0, sizeof(vis));
		memset(v, 0, sizeof(v));
		memset(c, 0, sizeof(c));
		int n, k, m, a, b; 
		cin >> n >> k >> m; 
		
		for (int i = 0; i < m; i++){
			cin >> a >> b;
			a--, b--;
			v[a][b]++;
			v[b][a]++;
			c[a]++;
			c[b]++;
		}
		int res = n;
		priority_queue<pair < int, int > > q;
		for (int i = 0; i < n; i++){
			q.push(mp(-c[i], i));
		}
		while (!q.empty()){
		
			int nod = q.top().second;
			int kk = -q.top().first;
			q.pop();
			vis[nod] = 1;
			
			if (kk < k){
				for (int i = 0; i < n; i++){
					if (v[nod][i]){
						v[nod][i]--;
						v[i][nod]--;
						c[i]--;
						c[nod]--;
					}
				}
			}
			else
				break;
			while (!q.empty())
				q.pop();
			res--;
			for (int i = 0; i < n; i++){
				if (!vis[i])
					q.push(mp(-c[i], i));
			}

		}
		cout << res << endl;
	}

	return 0;
}