#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
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
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int main() {

	//freopen("a.txt", "rt", stdin);

	int n, a, b;
	cin >> n >> a;
	int c = 1;
	vector<long long> v;
	for (int i = 1; i < n; i++) {
		cin >> b;
		if (b != a) {
			v.push_back(c);
			c = 1;
		} else
			c++;
		a = b;
	}
	v.push_back(c);
	long long sum = 0;
	for (int i = 0; i < v.size(); i++)
		sum += v[i] + (v[i] * (v[i] - 1) / 2);
	cout << sum << endl;
	return 0;

}

