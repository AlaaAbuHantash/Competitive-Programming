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
int a[101][101][101];
int main() {

	int t = 1;
	//freopen("test.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);

	int n, r, c, k; 
	while (scanf("%d%d%d%d", &n, &r, &c, &k) > 0){
		if (n + c + r + k == 0)
			break;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				scanf("%d", &a[0][i][j]);


		for (int kk = 0; kk < k; kk++){
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++){
					int x = a[kk][i][j];
					a[kk + 1][i][j] = a[kk][i][j];
					for (int d = 0; d < 4; d++){
						int xx = dx[d] + i;
						int yy = dy[d] + j;
						if (xx >= 0 && yy >= 0 && xx < r&&yy < c){
							if (a[kk][xx][yy] + 1 == x)
								a[kk + 1][i][j] = a[kk][xx][yy];
							else if (x == 0 && a[kk][xx][yy] + 1 == n)
								a[kk + 1][i][j] = a[kk][xx][yy];
						}

					}
				}
		}
		for (int i = 0; i < r; i++){
			printf("%d", a[k][i][0]);
			for (int j = 1; j < c; j++)
				printf(" %d", a[k][i][j]);
			puts("");
		}
	}
	return 0;
}

