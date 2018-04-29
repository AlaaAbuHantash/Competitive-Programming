#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<map>
using namespace std;
#define eps 1e-9
#define mp make_pair
int dx[] = { -1, 0, 0, 1, 1, 1, -1, -1 };
int dy[] = { 0, -1, 1, 0, 1, -1, 1, -1 };
int main() {
	string s;
	cin >> s;
	if (s[0] == '-') {
		s.erase(0, 1);
		if ((s <= "128" && s.length() == 3) || s.length() < 3)
			puts("byte");
		else if ((s <= "32768" && s.length() == 5) || s.length() < 5)
			puts("short");
		else if ((s <= "2147483648" && s.length() == 10) || s.length() <10)
			puts("int");
		else if ((s <= "9223372036854775808" && s.length() == 19)
				|| s.length() < 19)
			puts("long");
		else
			puts("BigInteger");
	} else if ((s <= "127" && s.length() == 3) || s.length() < 3)
		puts("byte");
	else if ((s <= "32767" && s.length() == 5) || s.length() < 5)
		puts("short");
	else if ((s <= "2147483647" && s.length() == 10) || s.length() < 10)
		puts("int");
	else if ((s <= "9223372036854775807" && s.length() == 19) || s.length() < 19)
		puts("long");
	else
		puts("BigInteger");

	return 0;
}

