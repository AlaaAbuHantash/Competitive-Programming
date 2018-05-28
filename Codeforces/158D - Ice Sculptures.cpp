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
int dx[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
int dy[] = { 0, 1, 0, -1, -1, -1, 1, 1 };
#define mp make_pair
int main() {
	//freopen("test.txt", "rt", stdin);

	int n, x;
	scanf("%d", &n);
	vector<int> v;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		v.push_back(x);
	}
	int res = -1;
	for (int i = 1; i < n; i++) {

		if (n % i == 0 && n / i >= 3) {
			for (int k = 0; k < i; k++) {
				int sum = 0;
				for (int j = k; j < n; j += i)
					sum += v[j];
				if (res == -1 || sum > res)
					res = sum;
			}
		}
	}
	printf("%d\n", res);
	return 0;
}


