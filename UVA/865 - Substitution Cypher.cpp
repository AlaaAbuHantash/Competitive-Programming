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
int main() {

//freopen("input.in" , "rt" , stdin);
//freopen ("myfile.txt","w",stdout);

	int t;
	string s, a, b;
	scanf("%d", &t);
	getline(cin, s);
	getline(cin, s);
	bool f = 0;
	while (t--) {
		if (f)
			puts("");
		f = 1;
		map<char, char> m;
		getline(cin, a);
		getline(cin, b);
		for (int i = 0; i < a.length(); i++)
			m[a[i]] = b[i];
		cout << b << "\n" << a << "\n";
		while (getline(cin, s) && s.length()) {

			for (int i = 0; i < s.length(); i++)
				if (m.find(s[i]) != m.end())
					printf("%c", m[s[i]]);
				else
					printf("%c", s[i]);
			puts("");
		}

	}
	return 0;
}


