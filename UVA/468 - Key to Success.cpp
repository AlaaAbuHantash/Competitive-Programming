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
int main() {
	//freopen("A.txt", "rt", stdin);
	int t;
	string a, b;
	scanf("%d", &t);
	map<char, char> m;
	bool f = 0 ;
	while (t--) {
		if(f)
			puts("");
		f=1;
		cin >> a >> b;
		m.clear();
		vector<int> v(60), v2(60);
		vector<pair<int, int> > aa, bb;
		for (int i = 0; i < a.size(); i++)
			if (a[i] >= 'A' && a[i] <= 'Z')
				v[a[i] - 'A' + 28]++;
			else if (a[i] >= 'a' && a[i] <= 'z')
				v[a[i] - 'a']++;

		for (int i = 0; i < b.size(); i++) {
			if (b[i] >= 'A' && b[i] <= 'Z')
				v2[b[i] - 'A' + 28]++;
			else if (b[i] >= 'a' && b[i] <= 'z')
				v2[b[i] - 'a']++;
		}

		for (int i = 0; i < 60; i++)
			if (v[i])
				aa.push_back(mp(v[i], i));

		for (int i = 0; i < 60; i++)
			if (v2[i])
				bb.push_back(mp(v2[i], i));

		sort(aa.rbegin(), aa.rend());
		sort(bb.rbegin(), bb.rend());
		for (int i = 0; i < aa.size() && i < bb.size(); i++)
			m[bb[i].second] = aa[i].second;

		for (int i = 0; i < b.size(); i++) {
			if (b[i] >= 'A' && b[i] <= 'Z') {
				int x = b[i] - 'A' + 28;
				if (m[x] >= 26)
					cout << char(m[x] + 'A'-28);
				else
					cout << char(m[x] + 'a');
			} else if (b[i] >= 'a' && b[i] <= 'z') {
				int x = b[i] - 'a';
				//cout << b[i] << " " << "x " <<x << endl;
				if (m[x] >= 26)
					cout << char(m[x] + 'A'-28);
				else
					cout << char(m[x] + 'a');
			} else
				cout << b[i];

		}
		puts("");
	}
	return 0;
}

