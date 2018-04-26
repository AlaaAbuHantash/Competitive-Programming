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
#include <stdio.h>
#include <fstream>
#define mp make_pair
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
map < int, int > m; 
int c; 
int main() {
	//freopen("test.txt", "rt", stdin);
	int n; 
	c = 0;
	cin >> n; 
	vector<int > v; 
	int a; 
	for (int i = 0; i < n; i++){
		cin >> a; 
		while (a % 2 == 0)
			a /= 2;
		while (a % 3 == 0)
			a /= 3;

		if (!m[a])
			c++;
		m[a] = 1;
	}

	if (c == 1)
		puts("YES");
	else
		puts("NO");


}

