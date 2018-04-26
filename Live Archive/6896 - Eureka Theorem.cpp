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
using namespace std;
#define mp make_pair
#define eps 1e-6
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int a[100];
int m[50000];
int main() {
	//freopen("test.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);
	a[1] = 1;
	for (int i = 2; i < 50; i++){
		a[i] = a[i - 1] + i;
	}

	for (int i = 1; i < 50; i++)
		for (int j = 1; j < 50; j++)
			for (int k = 1; k < 50; k++)
				m[a[i] + a[j] + a[k]] = 1;
	int t, n; 
	cin >> t; 
	while (t--){
		cin >> n;
		if (m[n])
			puts("1");
		else
			puts("0");
	
	}

	return 0;
}