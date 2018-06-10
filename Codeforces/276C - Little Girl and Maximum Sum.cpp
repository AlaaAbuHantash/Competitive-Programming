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
/*YOU got a DREAM, YOU gotta protect it. */
using namespace std;
int main() {
	//freopen("test.txt", "rt", stdin);
	int n, m, x, a, b;
	scanf("%d%d", &n, &m);
	vector<int> v, arr;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		v.push_back(x);
		arr.push_back(0);
	}
	sort(v.rbegin(), v.rend());
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		arr[a - 1]++;
		if (b < n)
			arr[b]--;

	}
	for (int i = 1; i < n; i++) {
		arr[i] += arr[i - 1];
	}

	sort(arr.rbegin(), arr.rend());
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0)
			break;
		sum += (long long) arr[i] * (long long) v[i];
	}
	cout << sum << endl;


	return 0;

}

