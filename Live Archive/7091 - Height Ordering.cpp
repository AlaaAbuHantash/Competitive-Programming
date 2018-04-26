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

int main() {
	//freopen("test.txt", "rt", stdin);
	int t, n, g;
	int a[22];
	cin >> t;
	while (t--){
		cin >> g;
		for (int i = 0; i < 20; i++)
			cin >> a[i];
		int res=0; 
		for (int i = 0; i < 20; i++)
			for (int j = i + 1; j < 20; j++)
				if (a[i]>a[j])
					res++;
		printf("%d %d\n", g, res);
	}
}

