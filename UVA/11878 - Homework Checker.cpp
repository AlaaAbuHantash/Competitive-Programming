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

int main() {
	//freopen("A.txt", "r", stdin);
	//freopen ("myfile.txt","w",stdout);
	string s;
	int res = 0;
	while (cin >> s) {
		//if (s == "#")
		//break;
		//cout << s << endl;
		int a = 1, i = 0, b = 1, c = 1;
		int n = s.length();
		if (s[0] == '-') {
			a = -1;
			i = 1;
		}

		string aa = "", bb = "", cc = "";
		bool f = 0, ff = 0;
		for (; i < n; i++) {
			//cout << aa << " " << bb << " " << cc << " " << s[i] << " " << i << endl;
			if (s[i] != '-' && s[i] != '+' && !f) {
				aa += s[i];
			} else if (s[i] == '-' || s[i] == '+') {

				f = 1;
				if (s[i] == '-')
					b = -1;
				if (s[i + 1] == '-' || s[i + 1] == '+') {
					if (s[i + 1] == '-' && b == 1)
						b = -1;
					else if (s[i + 1] == '-')
						b = 1;
					i++;
				}
			} else if (s[i] != '-' && s[i] != '+' && s[i] != '=' && !ff) {
				//cout << "f" << " " << i << " " << s[i] << endl;
				bb += s[i];
			} else if (s[i] == '=') {
				ff = 1;
			} else {
				//cout <<" g " << s[i] << endl;
				if (s[i] == '-')
					c = -1;
				if (s[i] == '+' || s[i] == '?')
					continue;
				cc += s[i];
			}

		}
		if (!cc.size())
			continue;
		else {
			a = a * atoi(aa.c_str());
			b = b * atoi(bb.c_str());
			c = c * atoi(cc.c_str());
			//cout << a << " " << b << " " << c << endl;
			if (a + b == c)
				res++;
		}
	}
	printf("%d\n", res);
	return 0;

}


