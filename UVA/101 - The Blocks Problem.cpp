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
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int main() {
	//freopen("test.txt", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);
	int n, x, y;
	string s;
	scanf("%d", &n);

	vector<vector<int> > v(n);
	for (int i = 0; i < n; i++)
		v[i].push_back(i);

	while (cin >> s && s != "quit") {
		if (s == "move") {
			scanf("%d", &x);
			cin >> s;
			scanf("%d", &y);
			if (x == y)
				continue;
			int xx = -1, yy = -1;

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < v[i].size(); j++)
					if (v[i][j] == x)
						xx = i;
					else if (v[i][j] == y)
						yy = i;
			}
			if (xx == yy)
				continue;
			if (s == "onto") {
				bool f = 0, ff = 0;
				for (int i = 0; i < n; i++)
					for (int j = 0; j < v[i].size(); j++)
						if (v[i][j] == x && !f) {
							for (int k = v[i].size() - 1; k >= 0; k--) {
								if (v[i][k] == x) {
									f = 1;
									v[i].pop_back();
									break;
								}
								v[v[i][k]].push_back(v[i][k]);
								v[i].pop_back();
							}
						}

				for (int i = 0; i < n; i++)
					for (int j = 0; j < v[i].size(); j++)
						if (v[i][j] == y && !ff) {
							for (int k = v[i].size() - 1; k >= 0; k--) {
								if (v[i][k] == y) {
									ff = 1;
									v[i].push_back(x);
									break;
								}
								v[v[i][k]].push_back(v[i][k]);
								v[i].pop_back();
							}

						}

			} else if (s == "over") {
				bool f = 0, ff = 0;
				for (int i = 0; i < n; i++)
					for (int j = 0; j < v[i].size(); j++)
						if (v[i][j] == x && !f) {
							for (int k = v[i].size() - 1; k >= 0; k--) {
								if (v[i][k] == x) {
									f = 1;
									v[i].pop_back();
									break;
								}
								v[v[i][k]].push_back(v[i][k]);
								v[i].pop_back();
							}
						}

				for (int i = 0; i < n; i++)
					for (int j = 0; j < v[i].size(); j++)
						if (v[i][j] == y && !ff) {
							ff = 1;
							v[i].push_back(x);
							break;

						}
			}

		} else if (s == "pile") {
			scanf("%d", &x);
			cin >> s;
			scanf("%d", &y);
			if (x == y)
				continue;
			int xx = -1, yy = -1;

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < v[i].size(); j++)
					if (v[i][j] == x)
						xx = i;
					else if (v[i][j] == y) {
						yy = i;

					}
			}

			if (xx == yy)
				continue;
			if (s == "onto") {
				bool f = 0, ff = 0;
				int ind;
				for (int i = 0; i < n && !f; i++)
					for (int j = 0; j < v[i].size() && !f; j++)
						if (v[i][j] == y && !f) {
							ind = i;
							for (int k = v[i].size() - 1; k >= 0; k--) {
								if (v[i][k] == y) {
									f = 1;
									break;
								}
								v[v[i][k]].push_back(v[i][k]);
								v[i].pop_back();
							}
						}

				f = 0;
				int r = 0;
				for (int i = 0; i < n && !f; i++)
					for (int j = 0; j < v[i].size() && !f; j++)
						if (v[i][j] == x && !f) {
							for (int k = j; k < v[i].size(); k++) {
								v[ind].push_back(v[i][k]);
								r++;
								f = 1;
							}
							while (r--)
								v[i].pop_back();
						}

			} else if (s == "over") {
				int ind;
				bool f = 0;
				for (int i = 0; i < n && !f; i++)
					for (int j = 0; j < v[i].size() && !f; j++)
						if (v[i][j] == y && !f) {
							ind = i;
							f = 1;
							break;

						}

				f = 0;
				int r = 0;
				for (int i = 0; i < n && !f; i++) {

					for (int j = 0; j < v[i].size() && !f; j++) {
						if (v[i][j] == x && !f) {
							for (int k = j; k < v[i].size(); k++) {
								v[ind].push_back(v[i][k]);
								r++;
								f = 1;
							}
							while (r--)
								v[i].pop_back();

						}
					}
				}

			}

		}

	}
	for (int i = 0; i < n; i++) {
		printf("%d:", i);
		for (int j = 0; j < v[i].size(); j++)
			printf(" %d", v[i][j]);
		puts("");

	}

	return 0;
}

