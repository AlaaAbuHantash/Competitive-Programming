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

int main() {
	//freopen("test.txt", "rt", stdin);
	int x, y;
	string s;
	cin >> x >> s;
	reverse(s.begin(), s.end());
	y = atoi(s.c_str());
	cout << x + y << endl;
	return 0;
}

