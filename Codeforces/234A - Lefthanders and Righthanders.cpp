#include<iostream>
#include<string>
#include <stdlib.h>
#include<stdio.h>
#include<vector>
using namespace std;
int vis[111];
#define mp make_pair
int main() {
	freopen("input.txt" , "rt" , stdin);
 	freopen ("output.txt","w",stdout);
	int t;
	string s;
	cin >> t >> s;
	vector<int> v;
	for (int i = 0; i < t; i++)
		if (s[i] == 'R')
			vis[i] = 1;
	for (int i = 0; i < t/2	; i++) {
		int x = i;
		int y = (i + (t / 2)) % t;
		if (vis[x]) {
			printf("%d %d\n", y + 1, x + 1);
		} else
			printf("%d %d\n", x + 1, y + 1);
	}

	return 0;
}

