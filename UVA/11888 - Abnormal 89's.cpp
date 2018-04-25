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
#define mp make_pair
#define eps 1e-6
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int t, n, m;
string s, a, b, tmp;
vector<int> bb;
void kmpPreprocess() {
	bb.clear();
	bb.resize(m + 2);
	int i = 0, j = -1;
	bb[0] = -1;
	while (i < m) {
		while (j >= 0 && s[i] != s[j])
			j = bb[j];
		i++;
		j++;
		bb[i] = j;
	}
}
 
int main() {
	//freopen("A.txt", "rt", stdin);
	scanf("%d", &t);
	while (t--) {
		bool p = 0, f = 0;
		cin >> s;
		tmp = s;
		b = s;
		n = s.length();
		if (n == 1) {
			puts("palindrome");
			continue;
		}
		reverse(tmp.begin(), tmp.end());
		s = s + "@" + tmp;
		m = s.length();
		kmpPreprocess();
		if (bb[m] == n) {
			p = 1;
			string tmp2 = s.substr(0, n / 2);
			a = tmp2;
			reverse(a.begin(), a.end());
 
			if (a == tmp2 && n % 2 == 0)
				f = 1;
			else {
				tmp2 = b.substr(0,n / 2);
				string tmp3 = b.substr(n / 2);
				string b = tmp3;
				a = tmp2;
				reverse(a.begin(), a.end()); reverse(b.begin(), b.end());
				if (a == tmp2 && b ==tmp3)
					f = 1;
 
			}
 
		}
		else {
			string tmp2 = b.substr(bb[m]);
			a = tmp2;
			reverse(a.begin(), a.end());
			if (a == tmp2)
				f = 1;
			s = tmp + "@" + b;
			kmpPreprocess();
			tmp2 = tmp.substr(bb[m]);
			a = tmp2;
			reverse(a.begin(), a.end());
			if (a == tmp2)
				f = 1;
 
		}
 
		if (f)
			puts("alindrome");
		else if (p)
			puts("palindrome");
		else
			puts("simple");
 
	}
 
	return 0;
}