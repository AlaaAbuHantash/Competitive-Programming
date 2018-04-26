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

	int n;
	cin >> n;
	int a = 1, b = n;
	if (n % 2 == 1) {
		cout << 1;
		a++;
	}

	while (a <= b) {
		cout << " " << b << " " << a;
		a++;
		b--;
	}
	return 0;
}

