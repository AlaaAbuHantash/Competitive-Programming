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
int n, k, x;
map<int, int> vis;
int main() {
	//freopen("test.txt", "rt", stdin);
	scanf("%d%d", &n, &k);
	vector<int> v, r;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x % k) {
			r.push_back(x);
			vis[x] = 2;
		} else {
			v.push_back(x);
			vis[x] = 1;
		}
	}
	sort(v.rbegin(), v.rend());
	for (int i = 0; i < v.size(); i++) {
		if (vis[v[i]] == 1 && vis[v[i] / k] != 2) {
			r.push_back(v[i]);
			vis[v[i] / k] = 2;
		}
	}
	cout << r.size() << endl;
	return 0;
}

