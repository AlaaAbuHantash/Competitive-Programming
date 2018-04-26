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

string s[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
		".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...",
		"-", "..-", "...-", ".--", "-..-", "-.--", "--.." };

string tar, g;
int n, len;
vector<string> v;
int vis[22];
string ss;
int dp[10005];
int calc(int pos) {

	if (ss == tar)
		return 1;
	int r = 0;
	if (dp[pos] != -1)
		return dp[pos];
	for (int i = 0; i < n; i++) {
		if (pos + v[i].length() <= len) {
			bool f = 0;
			for (int j = 0; j < v[i].length() && !f; j++)
				if (v[i][j] != tar[j + pos])
					f = 1;
			if (!f) {
				ss += v[i];
				r += calc(pos + v[i].length());
				ss.resize(ss.length() - v[i].length());
			}
		}
	}
	return dp[pos] = r;
}
int main() {

	//freopen("a.txt", "rt", stdin);
	int t;
	cin >> t;
	while (t--) {
		v.clear();
		memset(dp, -1, sizeof(dp));
		memset(vis, 0, sizeof(vis));
		cin >> tar >> n;
		len = tar.length();
		for (int i = 0; i < n; i++) {
			cin >> g;
			string tmp = "";
			for (int j = 0; j < g.length(); j++)
				tmp += s[g[j] - 'A'];
			v.push_back(tmp);
		}
		ss = "";
		cout << calc(0) << endl;
	}
	return 0;
}

