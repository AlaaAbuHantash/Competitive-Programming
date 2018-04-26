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
int main() {
	string s, b;
	cin >> s >> b;
	if (s.length() != b.length()) {
		puts("NO");
	} else {
		if (s == b)
			puts("YES");
		else {
			int aa = 0, bb = 0;
			for (int i = 0; i < s.length(); i++) {
				if (s[i] == '0')
					aa++;
				if (b[i] == '0')
					bb++;
			}

			if (aa == s.length() || bb == s.length() || s.length() == 1)
				puts("NO");
			else
				puts("YES");
		}
	}
	return 0;
}

