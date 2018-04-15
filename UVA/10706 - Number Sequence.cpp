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

int n, t;
map<long long, int> arr;
int main() {
	//freopen("test.txt", "rt", stdin);
	arr[0] = 0;
	long long k = 0;
	vector<long long> v;
	for (int i = 1; k <= 2157483647; i++) {
		int x = 1;
		if (i >= 10)
			x++;
		if (i >= 100)
			x++;
		if (i >= 1000)
			x++;
		if (i >= 10000)
			x++;
		if (i >= 100000)
			x++;
		if (i >= 1000000)
			x++;
		if (i >= 10000000)
			x++;
		arr[i] += arr[i - 1] + x;
		k += arr[i];
		v.push_back(k);
		//cout << k << "  "<<  i << " " << x << " " << " " << arr[i] << endl;

	}
	string res = "";
	//31337
	for (int i = 1; i <= 31337; i++) {
		stringstream a;
		string s;
		a << i;
		a >> s;
		res += s;
	}

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		//31337
		if (n == 1)
			printf("1\n");
		else {
			int xx = lower_bound(v.begin(), v.end(), n) - v.begin();
			xx--;
			n -= v[xx];

			printf("%d\n", res[n-1]-'0');
		}

	}
	return 0;
}
