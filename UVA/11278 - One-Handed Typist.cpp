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

	string a =
			"`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./ ~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
	string b =
			"`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg' ~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";

	string s;
	map<char, char> m;
	for (int i = 0; i < a.length(); i++)
		m[a[i]] = b[i];
	while (getline(cin, s)) {
		int len = s.length();
		for (int i = 0; i < len; i++)
			printf("%c", m[s[i]]);
		puts("");
	}
	return 0;
}


