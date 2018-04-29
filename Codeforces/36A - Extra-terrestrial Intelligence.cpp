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

int main() {
//	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);
	int n, st;
	string s;
	cin >> n >> s;
	set<int> ss;
	int r = 0, g = 0,f=0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0' && g) {
			r++;
		} else if (s[i] == '1') {
			g = 1;
			if(f)
			ss.insert(r);

			r = 0;
			f=1;
		}
	}
	if (ss.size() <= 1)
		puts("YES");
	else
		puts("NO");
	return 0;
}

