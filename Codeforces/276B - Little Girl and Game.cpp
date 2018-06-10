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
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
string s;
int a[30];
int main() {
	//freopen("input", "rt", stdin);
	cin >> s;
	int c = 0;
	for (int i = 0; i < s.length(); i++)
		a[s[i] - 'a']++;
	for (int i = 'a'; i <= 'z'; i++)
		if (a[i - 'a'] % 2)
			c++;

	if (c == 0 || c % 2)
		puts("First");
	else
		puts("Second");
	return 0;
}

