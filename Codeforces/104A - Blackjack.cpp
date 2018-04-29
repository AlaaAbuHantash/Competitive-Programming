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
	int a[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 11, 10, 10, 10 };

	int n, res = 0;
	cin >> n;
	n -= 10;
	for (int i = 0; i < 14; i++)
		if (a[i] == n)
			res += 4;
	if (n == 10)
		res--;
	cout << res << endl;
	return 0;
}

