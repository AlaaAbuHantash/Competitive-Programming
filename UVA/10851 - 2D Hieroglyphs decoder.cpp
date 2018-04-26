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

string s[11];
int m;
int main() {

	//freopen("A.txt" , "rt" , stdin);
	//freopen ("myfile.txt","w",stdout);

	int t;
	// \/  -- 1 0
	scanf("%d", &t);
	while (t--) {

		for (int i = 0; i < 10; i++)
			cin >> s[i];
		//1001100
		m = s[0].length();
		for (int j = 1; j < m - 1; j++) {
			int sum = 0, x = 0;
			for (int i = 1; i < 9; i++,x++) {
				if (s[i][j] == '\\')
					sum+=pow(2.0,x);
			}
			cout<<(char)sum;
		}
		puts("");
	}
	return 0;
}


