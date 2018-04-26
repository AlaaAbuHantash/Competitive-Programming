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
int n; 
int a[1001];
int dp[10001];
int calc(int ind){

	if (ind >= n-1)
		return a[n-1];
	if (dp[ind] != -1)
		return dp[ind];
	int aa = 1e4, bb = 1e4;
	aa = min(a[ind], calc(ind + 1));
	bb = min(a[ind], calc(ind + 2));

	return dp[ind]= max(aa, bb);
}
int main() {

	//freopen("test.txt", "rt", stdin);
	cin >> n; 
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++)
		cin >> a[i]; 
	cout << calc(0) << endl;
	return 0;
}