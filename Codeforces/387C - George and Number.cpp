#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
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
bool comp(string a, string b) {
	if (a.length() != b.length())
		return a.length() > b.length();
	return a >= b;
}
int main() {
	//freopen("a.txt", "rt", stdin);
	string s ;
	cin >> s ;
	string tmp = "";
	vector<string> v;
	for (int i = s.length()- 1; i >= 0; i--) {
		tmp = s[i] + tmp;
		if (s[i] == '0')
			continue;
		v.push_back(tmp);
		//cout << tmp << endl;
		tmp = "";
	}

	int c = 1;
	int len = v.size() - 1;
	string beg = v[len];
	for (int i = len - 1; i >= 0; i--) {
		if (comp(beg, v[i]))
			c++;
		else
			c = 1;
		beg += v[i];
	}
	cout << c << endl;
	return 0;
}

