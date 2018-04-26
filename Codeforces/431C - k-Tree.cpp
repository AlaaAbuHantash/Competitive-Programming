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
const int M = 1e9 + 7;
int n, k, d; 
int dp[200][2];
int calc(int sum,int f ){
	if (sum == n&&f)
		return 1; 
	if (sum >= n)
		return 0; 
	if (dp[sum][f] != -1)
		return dp[sum][f];
	int res = 0;
	for (int i = 1; i <= k; i++){
		if (i >= d)
			res += calc(sum + i, 1);
		else
			res += calc(sum + i, f);
		res %= M;
	}
	return dp[sum][f]=res;
}
int main() {

	//freopen("test.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> k >> d;
	memset(dp, -1, sizeof(dp));
	cout << calc(0, 0) % M << endl;
	return 0;
}

