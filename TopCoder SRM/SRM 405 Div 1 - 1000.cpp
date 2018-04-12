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
#define mp make_pair
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
class IdealString {
public:
	int v[111], len, f;
	vector<int> cnt;
	string res;
	string construct(int length) {
		memset(v, 0, sizeof(v));
		len = length;
		f = 0;
		cnt.clear();
		cnt.resize(30);
		res = "#";
		v[0] = 1;
		calc(0, length - 1, 1);

		if (f) {
			for (int i = 0; i < res.length(); i++)
				if (res[i] != '#')
					cnt[res[i] - 'A'] = i;
				else
					for (int j = 0; j < 26; j++) {
						if (cnt[j] > 0) {
							cnt[j]--;
							res[i] = char(j + 'A');
							break;
						}
					}
			//cout << res <<endl;
			return res;
		}
		return "";
	}
	void calc(int h, int nub, int pos) {
		//cout << " " << h << " " << nub << " " << pos << endl;
		if (nub == h && pos + h == len) {
			string tmp = "";
			char a = 'A';
			for (int i = 0; i < len; i++) {
				if (v[i]) {
					tmp += char(a);
					a++;
				} else {
					tmp += "#";
				}
			}
			if (res == "#")
				res = tmp;
			res = min(res, tmp);
			f = 1;
			return;
		}
		if (pos > len)
			return;
		if (h >= 1) {
			calc(h - 1, nub - 1, pos + 1);
		}
		if (pos + 1 + h <= nub) {
			v[pos] = 1;
			calc(h + pos, nub - 1, pos + 1);
			v[pos] = 0;
		}
	}
};
