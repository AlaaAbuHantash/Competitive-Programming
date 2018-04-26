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

	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b;
	cin >> a >> b;
	int x = max(a, b);
	vector<int> v;
	for (int i = 1; i * i <= x; i++)
		if (b % i == 0 || a % i == 0) {
			if (b % i == 0 && a % i == 0)
				v.push_back(i);
			int y = b / i;
			if (b % y == 0 && a % y == 0 && y != i)
				v.push_back(y);
			int z = a / i;
			if (b % z == 0 && a % z == 0 && z != i && y != z)
				v.push_back(z);

		}
	sort(v.begin(), v.end());
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		int x = lower_bound(v.begin(), v.end(), b) - v.begin();
		if (x >= v.size() || v[x] > b)
			x--;
		if (v[x] <= b && v[x] >= a)
			cout << v[x] << endl;
		else
			puts("-1");
	}
	return 0;
}

