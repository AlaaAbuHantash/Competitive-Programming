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
int n, m,a,b,q ; 
int v[555][555];
int main() {
	freopen("test.txt", "rt", stdin);
	while (scanf("%d%d", &n, &m) > 0){
		if (n + m == 0)
			return 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++){
				scanf("%d", &v[i][j]);
			}
		scanf("%d", &q);
		while (q--){
			scanf("%d%d", &a, &b);
			int res = -1;
			int row1 = 0, row2 = 0;
			for (int i = 0; i < n; i++){
				int aa = lower_bound(v[i], v[i] + m, a)-v[i];
				if (aa >= m){
					row1++; row2++;
					continue;
				}
				if (row2 >= n || row1 >= n)
					break;
				int bb = upper_bound(v[row2], v[row2] + m, b) - v[row2];
				if (bb == m || v[row2][bb] > b)
					bb--;
				while (bb >= aa && bb - aa + 1 > res){
					res = row2 - row1 + 1;
					row2++;
					if (row2 >= n)
						break;
					bb = upper_bound(v[row2], v[row2] + m, b) - v[row2];

					if (bb==m||v[row2][bb] > b)
						bb--;
				}
				row1++;
				row2++;
				if (row2 >= n || row1 >= n)
					break;
			}
			if (res == -1)
				puts("0");
			else
				printf("%d\n", res); 
	
		}
		puts("-");
	}
}

