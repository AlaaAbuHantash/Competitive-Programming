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
int cnt[111];
int main() {
	//freopen("test.txt", "rt", stdin);
	int n, m,a ,b ,c; 
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++){
		scanf("%d%d%d", &a, &b,&c);
		cnt[a] += c;
		cnt[b] -= c;
	}
	int res = 0;
	for (int i = 1; i <= n; i++){
		if (cnt[i]>0)
			res += cnt[i];
		//cout << cnt[i] << endl;
	}
	printf("%d\n", res); 
}
