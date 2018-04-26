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
#include <stdio.h>
#include <fstream>
#define mp make_pair
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int cnt[33];
map<int, int> ma;
int main() {
	//freopen("b.txt", "rt", stdin);
	//memset(vis, -1, sizeof(vis));
	string s = "abcdefghijklmnopqrstuvwxyz";
	//cout << s.length() << endl;
	vector<string> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
	vector<int> ss;
	bool f = 1;
	vector<vector<int> > p(27);
	for (int i = 0; i < n && f; i++) {
		for (int k = i + 1; k < n && f; k++) {
			bool rr = 0;
			for (int j = 0; j < v[i].length() && j < v[k].length() && f; j++) {
				if (v[i][j] != v[k][j]) {
					rr = 1;


					//cout << "R " << endl;
					int y = v[k][j] - 'a';
					int x = v[i][j] - 'a';
					p[x].push_back(y);
					cnt[y]++;
					//cout <<  char ( y+'a' ) << endl;
					//if (ma[x])
					//  break;
					// vis[st] = x;
					//ma[x] = 1;
					//st++;
					break;
				}
			}
			if (!rr && v[i].length() > v[k].length())
				f = 0;
		}
	}

	if (!f)
		puts("Impossible");
	else {
		string res = "";
		queue<int> q;
		for (int i = 0; i < 26; i++)
			if (cnt[i] == 0)
				q.push(i);

		while (!q.empty()) {
			int fr = q.front();
			res += char(fr + 'a');
			q.pop();
			//cout << fr <<  " " << res << endl;
			for (int i = 0; i < p[fr].size(); i++) {
				cnt[p[fr][i]]--;
				if (cnt[p[fr][i]] == 0)
					q.push(p[fr][i]);
			}
		}
		if (res.length() == 26)
			cout << res << endl;
		else
			puts("Impossible");
	}
}