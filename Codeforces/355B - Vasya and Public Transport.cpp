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
#define mp make_pair
#define eps 1e-6
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int main() {
	int a, b, c, d, n, m, x;
	//	freopen("text.txt", "rt", stdin);
	cin >> a >> b >> c >> d >> n >> m;
	int cst = 0, cst2 = 0;
	for (int i = 0; i < n; i++){
		cin >> x;
		cst += min(b, a*x);
	}
	cst = min(cst, c);
	for (int i = 0; i < m; i++){
		cin >> x;
		cst2 += min(b, a*x);
	}
	cst2 = min(cst2, c);
	cst = min(cst + cst2, d);
	cout << cst << endl;
	return 0;
}