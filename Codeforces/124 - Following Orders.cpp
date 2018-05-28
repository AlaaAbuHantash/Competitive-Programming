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

#define mp make_pair
vector<int> v;
int a[30];
vector<string> r;
string rr;
int vis[30];
void calc(int msk, int nub) {
	if (nub == v.size()) {
		r.push_back(rr);
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		if (!vis[i] && (msk & a[v[i]]) == a[v[i]]) {
			vis[i] = 1;
			rr[nub] = 'a' + v[i];
			calc(msk | (1 << v[i]), nub + 1);
			vis[i] = 0;
		}
	}
}
int main() {
	//freopen("test.txt", "rt", stdin);
	string s;
	bool gg = 0;
	while (getline(cin, s)) {
		v.clear();
		r.clear();
		memset(a, 0, sizeof(a));
		if (gg)
			puts("");
		gg = 1;
		rr = "";
		for (int i = 0; i < s.length(); i++) {
			if (s[i] >= 'a' && s[i] <= 'z') {
				v.push_back(s[i] - 'a');
				rr += "0";
			}
		}

		getline(cin, s);
		bool f = 0;
		int c;

		for (int i = 0; i < s.length(); i++) {
			if (!f && s[i] >= 'a' && s[i] <= 'z') {
				c = s[i] - 'a';
				f = !f;
			} else if (f && s[i] >= 'a' && s[i] <= 'z') {
				f = !f;
				a[s[i] - 'a'] |= (1 << c);
			}

		}

		for (int i = 0; i < v.size(); i++) {
			if (a[v[i]] == 0) {
				vis[i] = 1;
				rr[0] = v[i] + 'a';
				calc(0 | (1 << v[i]), 1);
				vis[i] = 0;
			}
		}
		sort(r.begin(), r.end());
		for (int i = 0; i < r.size(); i++)
			cout << r[i] << endl;
	}

	return 0;
}

