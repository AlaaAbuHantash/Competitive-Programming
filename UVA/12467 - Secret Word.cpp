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
int t, n, m;
string s, a, tmp;
vector<int> b;
int res;
void kmpPreprocess() {
	b.clear();
	m = s.length();
	b.resize(m + 2);
	int i = 0, j = -1;
	b[0] = -1;
	bool f = 0;
	res = 0;
	while (i < m) {
		while (j >= 0 && s[i] != s[j])
			j = b[j];
		if (s[i] == '@')
			f = 1;
		if (f)
			res = max(res, j);
		i++;
		j++;
		b[i] = j;
	}
}
int main() {
	//freopen("A.txt", "rt", stdin);
	scanf("%d", &t);
	while (t--) {
		cin >> a;
		int len = a.length();
		s = a;
		reverse(s.begin(), s.end());
		s = a + "@" + s;
		kmpPreprocess();
		tmp = s.substr(0, res + 1);
		reverse(tmp.begin(), tmp.end());
		printf("%s\n", tmp.c_str());
	}

	return 0;
}

