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
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
#define mp make_pair
int vis[1000000],a,b,k,x;
int main() {

	int t= 1;
	//freopen("test.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);
	while (scanf("%d%d%d", &a, &b, &k) > 0){
		if (a + b + k == 0)
			return 0; 
		memset(vis, 0, sizeof(vis));
		vector<int > v; 
		for (int i = 0; i < k; i++){
			scanf("%d", &x);
			v.push_back(x % 10000);
		}
		queue<int > q; 
		q.push(a);
		vis[a] = 1;
		int res = 0,f=0;
		while (!q.empty()){
			int siz = q.size(); 
			while (siz--){
				int fr = q.front();

				q.pop();
				if (fr == b){
					f = 1; break;
				}
				vis[fr] = 1;
				for (int i = 0; i < k; i++){
					x = (fr + v[i])%10000;
					if (!vis[x])
						q.push(x);
					vis[x] = 1;
				}
			}
			if (f)break;
			res++;
		}
		if (f)
			printf("Case %d: %d\n", t++, res);
		else
			printf("Case %d: Permanently Locked\n",t++);
	}
	return 0;
}

