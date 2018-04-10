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
	int t, n, len, x;
	char s[100005], ss[100005];
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s);
		scanf("%d", &n);
		vector<int> f(26), tmp(26), vis(26);
		for (int i = 0; i < n; i++) {
			scanf("%s", ss);

			len = strlen(ss), x = 0;
			for (int j = 0; j < len - 1; j++)
				x = (x * 10) + (ss[j] - '0');
			f[ss[len - 1] - 'a'] = x;
			vis[ss[len - 1] - 'a'] = 1;
		}
		len = strlen(s);
		bool ff = 0;
		int ind = 0;
		int res = len;
		bool getall, findsubstr = 0;
		for (int i = 0; i < len; i++) {

			if (f[s[i] - 'a'] == 0 && !ff) {
				ind = i;
			} else {
				if (!ff)
					ind = i;
				ff = 1;
				getall = 1;
				tmp[s[i] - 'a']++;
				while (ind < i && tmp[s[ind] - 'a'] > f[s[ind] - 'a']) {
					tmp[s[ind] - 'a']--;
					ind++;
				}

				for (int j = 0; j < 26; j++)
					if (tmp[j] != f[j] && vis[j])
						getall = 0;

				if (getall) {
					findsubstr = 1;
					res = min(res, i - ind + 1);

				}

				while (ind < i && tmp[s[ind] - 'a'] > f[s[ind] - 'a']) {
					tmp[s[ind] - 'a']--;
					ind++;
				}

			}
		}

		getall = 1;
		while (ind < len && tmp[s[ind] - 'a'] > f[s[ind] - 'a']) {
			tmp[s[ind] - 'a']--;
			ind++;
		}
		for (int j = 0; j < 26; j++)
			if (tmp[j] != f[j] && vis[j])
				getall = 0;

		if (getall) {
			res = min(res, len - ind);
			findsubstr = 1;
		}
		if (findsubstr)
			printf("%d\n", res);
		else
			puts("-1");

	}

	return 0;
}
