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
char a[633], b[333];
int sa[633];
int lcp[633];
bool cmp(int aa, int bb) {
	return strcmp(a + aa, a + bb) < 0;
}
int main() {
	freopen("b.txt", "rt", stdin);
	bool f = 0;
	while (gets(a)) {
		gets(b);
		if (f)
			puts("");
		f = 1;
		memset(lcp, 0, sizeof(lcp));
		memset(sa, 0, sizeof(sa));
		int lena = strlen(a);
		a[lena] = '$';
		int lenb = strlen(b);
		for (int i = 0; i < lenb; i++)
			a[i + lena + 1] = b[i];
		a[lena + lenb + 1] = '#';
		//a[lena + lenb + 2] = '\0';
		int len = lena + lenb + 2;
		for (int i = 0; i < len; i++)
			sa[i] = i;
		sort(sa, sa + len, cmp);

		lcp[0] = 0;
		for (int i = 1; i < len; i++) {
			int l = 0;
			while (a[sa[i] + l] == a[sa[i - 1] + l])
				l++;
			lcp[i] = l;
		}

		int res = -1;
		vector<int> p;

		for (int i = 1; i < len; i++) {
			//cout << sa[i] << " " << sa[i - 1] << " " << lcp[i] << endl;
			if (sa[i - 1] > lena && sa[i] < lena) {
				if (lcp[i] > res) {
					res = lcp[i];
					p.clear();
					p.push_back(sa[i]);
				} else if (lcp[i] == res)
					p.push_back(sa[i]);
			} else if (sa[i] > lena && sa[i - 1] < lena) {
				if (lcp[i] > res) {
					res = lcp[i];
					p.clear();
					p.push_back(sa[i]);
				} else if (lcp[i] == res)
					p.push_back(sa[i]);
			}
		}

		map<string, int> m;
		if (res > 0) {
			for (int i = 0; i < p.size(); i++) {
				string s = "";
				for (int j = 0, x = p[i]; j < res; j++, x++)
					s += a[x];

				if (!m[s])
					printf("%s\n", s.c_str());
			}
		} else
			puts("No common sequence.");
		gets(b);
	}
	return 0;
}


