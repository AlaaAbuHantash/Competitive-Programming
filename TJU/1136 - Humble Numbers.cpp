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
map<long long, bool> m;
vector<long long> v;
void calc(long long x) {
	if (x > 2000000000)
		return;
	if (!m[x])
		v.push_back(x);
	else
		return;
	m[x] = 1;
	calc(x * 2);
	calc(x * 3);
	calc(x * 5);
	calc(x * 7);
}
int main() {
	//freopen("a.txt", "rt", stdin);
	calc(1);
	int n;
	sort(v.begin(), v.end());
	//cout << v.size() << endl;
	while (cin >> n && n) {
		if (n % 100 >= 10 && n % 100 <= 20)
			printf("The %dth humble number is %lld.\n", n, v[n - 1]);
		else if (n % 10 == 1)
			printf("The %dst humble number is %lld.\n", n, v[n - 1]);
		else if (n % 10 == 2)
			printf("The %dnd humble number is %lld.\n", n, v[n - 1]);
		else if (n % 10 == 3)
			printf("The %drd humble number is %lld.\n", n, v[n - 1]);
		else
			printf("The %dth humble number is %lld.\n", n, v[n - 1]);

	}
	return 0;
}
