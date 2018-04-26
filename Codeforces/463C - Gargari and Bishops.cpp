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
int a[2001][2001];
long long s[2001][2001];
long long ss[2001][2001];
int main() {

	//freopen("test.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);
	int n; 
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			scanf("%d", &a[i][j]);
		}


	for (int i = 0; i < n; i++){
		long long sum = 0;
		for (int j = i, k = 0; j < n&&k < n; j++,k++)
			sum += a[k][j];

		for (int j = i, k = 0; j < n&&k < n; j++, k++)
			s[k][j] = sum;

	}
	for (int i = 1; i < n; i++){
		long long sum = 0;
		for (int j = 0, k = i; k < n&&j < n; j++, k++)
			sum += a[k][j];

		for (int j = 0, k = i; k < n&&j < n; j++, k++)
			s[k][j] = sum;
	}

	for (int i = 0; i < n; i++){
		long long sum = 0;
		for (int j = i, k = 0; j >=0&&k < n; j--, k++)
			sum += a[k][j];

		for (int j = i, k = 0; j >=0&&k < n; j--, k++)
			ss[k][j] = sum;

	}

	for (int i = 1; i < n; i++){
		long long sum = 0;
		for (int j = n-1, k = i; k < n&&j>=0; j--, k++)
			sum += a[k][j];

		for (int j = n-1, k = i; k < n&&j >= 0; j--, k++)
			ss[k][j] = sum;
	}


	
	int xx, yy, xx2, yy2;
	long long res = 0,res2=0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			long long r = ss[i][j] + s[i][j] - a[i][j]; 
			if (r >= res)
				res = r, xx = i, yy = j;
		}


	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			long long r = ss[i][j] + s[i][j] - a[i][j];
			if ((abs(xx - i) % 2 == 1 && j == yy) || (abs(yy - j) % 2 == 1 && i == xx) || (abs(yy - j) % 2 == 1 && (abs(xx - i) % 2 == 0) )|| (abs(yy - j) % 2 == 0 && (abs(xx - i) % 2 == 1) ))
				if (r>=res2)
					res2 = r, xx2 = i, yy2 = j;
		}

	printf("%I64d %d %d %d %d\n", res + res2, xx + 1, yy + 1, xx2 + 1, yy2 + 1);
	return 0;
}

