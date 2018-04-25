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
string s, a;
int b[1000105];
void fun() {
	int m = s.length();
	int i = 0, j = -1;
	b[0] = -1;
	while (i < m) {
		while (j >= 0 && s[i] != s[j])
			j = b[j];
		i++, j++;
		b[i] = j;
	}
}
int res;
vector<int> v;
int aa[1000105];
void fun2(int x, int r) {
	if (x == 0) {
		v.push_back(x);
		return;
	}
	fun2(b[x], r + 1);
	v.push_back(x);
}
int main() {

	//freopen("b.txt", "rt", stdin);
	cin >> s;
	fun();
	int len = s.length();
	fun2(b[len], 1);
	bool f = 0;
	res = -1;

	if (len >= 3 && len % (len - b[len]) == 0) {
		int z = len - b[len];
		if (len / z >= 3)
			res = len - (2 * z);
	}

	for (int i = 1; i < len && b[len]; i++) {
		if (b[i] == b[len]) {
			if (res == -1)
				res = b[i];
			res = max(b[i], res);
			break;
		}
	}
	if (v.size() >= 4) {
		if (res == -1)
			res = v[v.size() - 2] - v[1] + 1;
		res = max(res, v[v.size() - 2] - v[1] + 1);
	} else if (v.size() == 3) {
		if (res == -1)
			res = v[1];
		res = max(res, v[1]);
	}

	if (res >= 1)
		cout << s.substr(0, res) << endl;
	else
		puts("Just a legend");

	return 0;
}

