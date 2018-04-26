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
int n, m, a, b, c; 
int d[1001];
int main() {
	//freopen("test.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);
	memset(d, -1, sizeof(d));
	cin >> n ; 
	for (int i = 0; i < n; i++)
		cin >> a; 
	cin >> m; 
	long long  res = 0;
	int cc = 0;
	for (int i = 0; i < m; i++){
		cin >> a >> b >> c; 
		if (a != b){
			if (d[b - 1] == -1)
				res += c, cc++, d[b - 1] = c;
			else if (c < d[b - 1]){
				res -= d[b - 1] - c;
				d[b - 1] = c;
			}
		}
	}
	if (cc+1 == n)
		cout << res << endl;
	else
		puts("-1");
	return 0;
}
