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

	//freopen("b.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);
	int n, l, r, k, sum, sk;
	cin >> n >> k >> l >> r >> sum >> sk;

	int x = sk / k;
	int mmod = sk % k;
	int s = sum - sk;
		int nub = n - k;
	while (mmod--) {
		cout << x + 1 << endl;
		k--;
	}
	while (k--)
		cout << x << endl;


	if (s) {
		int z = s / nub;
		int mod = s % nub;
		while (mod--) {
			cout << z + 1 << endl;
			nub--;
		}
		while (nub--)
			cout << z << endl;
	}

	return 0;
}

