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
map<int, int > m,l,r; 
vector<int > v; 
int a, b, n;
int main() {

	//freopen("test.txt", "rt", stdin);
	//freopen("myfile.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a >> b; 
		if (!m[a])
			v.push_back(a);
		if (!m[b])
			v.push_back(b);
		
		l[a]++;
		if (a != b)
		r[b]++;
	}
	int res = -1; 
	int mid = n / 2 + (n % 2 ? 1 : 0);
	for (int i = 0; i < n; i++){
		if (l[v[i]] + r[v[i]] >= mid){
			int x = mid - l[v[i]];
			if (x < 0)
				x = 0;
			if (res == -1 || x < res)
				res = x;
		}
	}
	cout << res << endl;
}