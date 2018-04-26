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
int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "w", stdout);

	int n, x;
	vector < int > v;
	cin >> n >> x;
	int a;
	for (int i = 0; i < n; i++){
		cin >> a; 
		a = a * (n - i);
		v.push_back(a);
	}
	int res = 0;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++){
		if (x >= v[i])
			res++, x -= v[i];
		else
			break;
	}
	cout << res << endl;
	return 0;
}