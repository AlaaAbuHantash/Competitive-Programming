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
int n, t,x; 
vector<int > v;
int dp[1000005];
int ccnt[350];
int main() {
	//freopen("test.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> t;
	for (int i = 0; i < n; i++){
		cin >> x;
		v.push_back(x);
	}
	int z = min(100, t)-1;
	
	for (int i = 0; i < z; i++){
		for (int j = 0; j < n; j++)
			v.push_back(v[j]);
	}


	int k = 0, nn = 0; 
	while (k < v.size()){
		int x = upper_bound(dp, dp + nn, v[k]) - dp;
		if (nn == x)
			nn++;
		dp[x] = v[k];
		k++;
	}
	if (t > 100){
		int z = t - 100;
		int c = 0; 

		for (int i = 0; i < n; i++){
			ccnt[v[i]]++, c = max(c, ccnt[v[i]]);
		}
		nn += (long long )z * (long long ) c ;
	}
	cout << nn << endl;
	return 0;
}
