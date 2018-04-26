#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
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
using namespace std;

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int c[33];
int one[33], two[33][33];
int main() {
	//freopen("test.txt", "rt", stdin);
	int n; 
	cin >> n; 
	string a; 
	int res = 0;
	for (int i = 0; i < n; i++){
		cin >> a; 
		memset(c, 0, sizeof(c));
		for (int j = 0; j < a.length(); j++)
			c[a[j] - 'a']++;
		
		vector<int>v;
		for (int j = 0; j < 26; j++){
			if (c[j]>0)
				v.push_back(j);
		}

		if (v.size() == 2){
			two[v[0]][v[1]] += a.length();
			two[v[1]][v[0]] += a.length();
		}
		else if (v.size() == 1)
			one[v[0]] += a.length();
	}

	for (int i = 0; i < 26; i++)
		for (int j = i + 1; j < 26; j++){
			int r = two[i][j] + one[i] + one[j];
			res = max(r, res);
		}

	cout << res << endl;
	return 0;
}