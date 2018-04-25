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
/*  You got a dream, you gotta protect it.*/

using namespace std;
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
vector<vector<int> > g;
vector<int> prefix;
vector<string> st;
string s;
void add() {
	int cur = 0;
	for (int i = 0; i < s.length(); i++) {
		if (g[cur][s[i] - 'a'] == -1) {
			g.push_back(vector<int>(30, -1));
			prefix.push_back(0);
			g[cur][s[i] - 'a'] = g.size() - 1;
		}
		cur = g[cur][s[i] - 'a'];
		++prefix[cur];
	}

}
int ckt() {
	int cur = 0;
	for (int i = 0; i < s.length(); i++) {
		cur = g[cur][s[i] - 'a'];
		if (prefix[cur] == 1)
			return i + 1;
	}
	return s.length();
}
int main() {
	//freopen("test.txt", "rt", stdin);
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		g.clear();
		prefix.clear();
		g.push_back(vector<int>(52, -1));
		prefix.push_back(0);
		st.clear();
		for (int i = 0; i < n; i++) {
			cin >> s;
			add();
			st.push_back(s);
		}
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			s = st[i];
			sum += ckt();
		}
		cout << sum << endl;

	}
	return 0;
}

