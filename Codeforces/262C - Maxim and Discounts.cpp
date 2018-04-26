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
using namespace std;
#define mp make_pair
int n, m, x, xx = 1e6, a[100001];
int main() {

	//freopen("test.txt", "rt", stdin);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x;
		xx = min(xx, x);
	}
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> a[i];
	sort(a, a + m);

	int sum = 0;

	for (int i = m - 1; i >= 0;i-=2)
		for (int j = 0; j < xx && i>=0; j++){
			sum += a[i];
			i--;
		}
	cout << sum << endl;
	return 0;
}