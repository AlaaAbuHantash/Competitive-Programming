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
		//freopen("A.txt" , "rt" , stdin);
		//freopen ("myfile.txt","w",stdout);
		int t;
		string s;
		scanf("%d", &t);
		while (t--) {
			cin >> s;
			int n = s.length();
			int f = 0, ff = 0, g = 1;
			int r = 0, rr = 0, rrr = 0;
			for (int i = 0; i < n; i++) {
				if (s[i] == 'M')
					f ++;
				else if (s[i] == 'E')
					ff ++;
				else if (s[i] == '?' && !f && !ff)
					r++;
				else if (s[i] == '?' && f && !ff)
					rr++;
				else if (s[i] == '?' && f && ff)
					rrr++;
				else
					g = 0;
			}
			if ((f ==1&& ff==1 && r == rrr - 1 && rr == 1 && rrr >= 2 && g)
					|| (f==1 && ff==1 && r + rr == rrr && rr >= 1 && rrr >= 1 && r >= 1
							&& g))
				puts("theorem");
			else
				puts("no-theorem");
		}
		return 0;

	}

 
