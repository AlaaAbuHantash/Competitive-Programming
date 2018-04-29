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

int main() {
	//freopen("test.txt", "rt", stdin);
	string s;
	vector<pair<string, string> > v;
	map<string, int> m;

	while (getline(cin, s) && s != "END") {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'b' && s[i + 1] == 'y') {
				string tmp = s.substr(0, i - 1);
				string tmp2 = s.substr(i + 3);
				v.push_back(mp(tmp2, tmp));

				break;
			}
		}
	}

	sort(v.begin(), v.end());
	vector<int> vis(v.size(), 1);
	vector<pair<string, string> > rr;
	for (int i = 0; i < v.size(); i++) {
		//cout << v[i].second << "-" << endl;
		m[v[i].second] = i;
		vis[i] = 1;
	}

	while (getline(cin, s) && s != "END") {
		string tmp = s.substr(0, 6);
		string g;
		if (tmp == "BORROW") {
			g = s.substr(7);
			vis[m[g]] = 0;
		} else if (tmp == "RETURN") {
			g = s.substr(7);
			vis[m[g]] = 1;
			rr.push_back(mp(v[m[g]].first, v[m[g]].second));
		} else {
			sort(rr.begin(), rr.end());
			vector<int> vv(v.size());
			for (int i = 0; i < rr.size(); i++) {
				if ( vv[m[rr[i].second]] || !vis[m[rr[i].second]])
					continue;
				vv[m[rr[i].second]]=1;
				vis[m[rr[i].second]] = 1;
				int x = m[rr[i].second];
				if (x == 0) {
					printf("Put ");
					cout << rr[i].second;
					printf(" first\n");
					continue;
				}
				bool ff = 0;
				while (x != 0) {
					x--;
					if (vis[x]) {
						ff = 1;
						break;
					}
				}
				if (ff) {
					printf("Put ");
					cout << rr[i].second;
					printf(" after ");
					cout << v[x].second << "\n";
				}
				if (!ff) {
					printf("Put ");
					cout << rr[i].second;
					printf(" first\n");
				}

			}
			rr.clear();
			for (int i = 0; i < v.size(); i++) {
				if (!vis[m[v[i].second]]) {
					//cout << v[i].second << endl;
					rr.push_back(mp(v[i].first, v[i].second));
				}
			}
			puts("END");
		}
	}

	return 0;
}


