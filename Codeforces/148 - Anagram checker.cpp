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
string s;
vector<string> v;
int a[33];
vector<string> re;
map<string, int> ma;
void calc(int nub, int ind) {
	//cout << nub << " " << ind << endl;
	if (ind == v.size()) {
		bool ff = 1;
		for (int i = 0; i < 30; i++)
			if (a[i])
				ff = 0;
		if (ff) {
			for (int i = 0; i < nub; i++)
				if (ma[re[i]])
					return;
			cout << s << " =";
			for (int i = 0; i < nub; i++)
				cout << " " << re[i];
			puts("");
		}
		return;
	}

	bool f = 1;
	vector<int> c(30);
	for (int i = 0; i < v[ind].length(); i++)
		if (a[v[ind][i] - 'A']) {
			a[v[ind][i] - 'A']--;
			c[v[ind][i] - 'A']++;
		} else {
			f = 0;
			break;
		}
	if (f) {
		re[nub] = v[ind];
		calc(nub + 1, ind + 1);
	}

	for (int i = 0; i < 30; i++)
		a[i] += c[i];
	re[nub] = "";

	calc(nub, ind + 1);
}

int main() {
	//freopen("test.txt", "rt", stdin);
	while (cin >> s && s != "#") {
		v.push_back(s);

	}
	sort(v.begin(), v.end());
	getline(cin, s);
	while (getline(cin, s) && s != "#") {

		istringstream A(s);
		string x;
		ma.clear();
		while (A >> x) {
			ma[x] = 1;
		}
		re.clear();
		re.resize(s.length());
		for (int i = 0; i <= 30; i++)
			a[i] = 0;
		for (int i = 0; i < s.length(); i++)
			if (s[i] >= 'A' && s[i] <= 'Z')
				a[s[i] - 'A']++;

		calc(0, 0);
	}
	return 0;
}


