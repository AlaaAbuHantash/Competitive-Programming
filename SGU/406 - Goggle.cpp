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
int fr[22][111];
int a[111];
int b[22];
int main() {
	//freopen("text.txt", "rt", stdin);

	int n, m,k,x; 
	scanf("%d%d", &n, &m);
	vector<vector<int > > v; 
	v.resize(n);
	for (int i = 0; i < n; i++){
		scanf("%d", &k);
		for (int j = 0; j < k; j++){
			scanf("%d", &x); 
			v[i].push_back(x);
			fr[i][x]++;
		}
	}

	for (int i = 0; i < m; i++){
		scanf("%d", &k);
		memset(a, 0, sizeof(a));
		for (int j = 0; j < k; j++){
			scanf("%d", &x);
			b[j] = x;
			if (x < 0)
				a[-x] = -1;
			else
				a[x]++;
		}
		vector<int > res; 
		for (int j = 0; j < n; j++){
			bool f = 1; 
			for (int g = 0; g < k && f ; g++){
				int xx = b[g]; 
			
				if (b[g] < 0){
					if (fr[j][-b[g]] == 0)
						continue;
					else
						f = 0;
				}
				else {
					if (fr[j][b[g]] >= a[b[g]])
						continue;
					else
						f = 0;
				}
			}
			
			if (f)
				res.push_back(j);
		}
		printf("%d\n", res.size());
		for (int j = 0; j < res.size(); j++){
			int xx = res[j];
			printf("%d", v[xx].size());
			for (int kk = 0; kk < v[xx].size(); kk++){
				printf(" %d", v[xx][kk]);;
			}
			puts("");
		}
	}
	return 0;
}

