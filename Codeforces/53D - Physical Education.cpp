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
const int N = 1e5;
int a[N + 10], c[N + 10];
//map<pair<int, int>, bool> ma;
int main() {

	//freopen("b.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> c[i];

	int res = 0;
	vector<pair<int, int> > v;
	for (int i = 0; i < n; i++) {
		if (c[i] == a[i])
			continue;
		int ind;
		for (int j = i + 1; j < n; j++) {
			if (c[j] == a[i]) {
				ind = j;
				break;
			}
		}
		for (int j = ind; j > i; j--) {
			swap(c[j], c[j - 1]);
			v.push_back(mp(j, j + 1));
		}

	}
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << " " << v[i].second << endl;
	return 0;
}

