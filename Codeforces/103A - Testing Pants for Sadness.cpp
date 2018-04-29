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
	long long  n, x, sum = 0;
	cin >> n;
	int pre = 0;
	int b = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		sum += x + ((x - 1) * pre);
		pre++;
	}
	cout << sum << endl;
	return 0;
}

