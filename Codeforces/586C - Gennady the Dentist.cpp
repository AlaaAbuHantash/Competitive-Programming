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
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int n;
int a, b, c;
int vis[4005];
int main() {
	//freopen("test.txt", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);
	cin >> n;
	vector<pair<pair<long long , long long >, long long > > v;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		v.push_back(mp(mp(a, b), c));
	}
	vector<int> res;
	for (int i = 0; i < n; i++) {
		int x = v[i].first.first;
		if (vis[i])
			continue;
		vis[i] = 1;
		long long c = 0;
		for (int j = i + 1; j < n; j++) {
			if (vis[j])
				continue;
			
			if (x)
				v[j].second -= x, x--;

			v[j].second -= c;

			if (v[j].second < 0) {
				vis[j] = 1; 
				c += v[j].first.second;
				res.push_back(j);
			}
			//cout << j << " " << v[j].second<< " " << c << endl;
		}
	}


	memset(vis, 0, sizeof(vis));
	int k = n;
	for (int i = 0; i < res.size(); i++) {
		int x = res[i];
		if (!vis[x])
			k--;
		vis[x] = 1;

	}
	cout << k << endl;
	for (int i = 0; i < n; i++)
		if (!vis[i])
			cout << i + 1 << " ";

	return 0;
}