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
#define eps 1e-6
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int main() {
	//freopen("a.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	int tt = 1;
	while (cin >> n && n) {
		string s;
		vector<pair<int, pair<int , string > > > st;
		for (int i = 0; i < n; i++) {
			cin >> s;
			st.push_back(mp(s.length(),mp(i, s)));
		}
		sort(st.begin(), st.end());
		vector<string> a, b;
		int f = 1;
		for (int i = 0; i < n; i++) {
			if (f)
				a.push_back(st[i].second.second);
			else
				b.push_back(st[i].second.second);
			f = !f;
		}
		printf("SET %d\n", tt++);
		for (int i = 0; i < a.size(); i++)
			cout << a[i] << endl;

		for (int i = b.size() - 1; i >= 0; i--)
			cout << b[i] << endl;

	}
	return 0;
}

