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
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int main() {
	//freopen("test.txt", "rt", stdin);

	string s;
	cin >> s;
	int res = 0 ;
	while (s.length() > 1) {
		int x = 0;
		for (int i = 0; i < s.length(); i++) {
			x += s[i] - '0';
		}
		s = "";
		while (x != 0) {
			s += (x % 10 + '0');
			x = x / 10;
		}
		res++;
	}
	cout << res << endl;
	return 0;
}

