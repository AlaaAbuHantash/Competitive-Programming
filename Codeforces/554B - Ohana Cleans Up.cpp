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
vector<string > s;
int n;
int vis[101];
int main() {

	//freopen("test.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	s.resize(n);
	for (int i = 0; i < n; i++)
		cin >> s[i];
	int id = 1,res=0,fres=0;
	for (int i = 0; i < n; i++){
		id++;
		for (int j = 0; j < n; j++)
			if (s[i][j] == '0')
				vis[j] = id;

		res = 0;
		for (int k = 0; k < n; k++){
			int r = 0;
			for (int j = 0; j < n; j++){
				if (vis[j] == id && s[k][j] == '0')
					r++;
				else if (s[k][j] == '1' && vis[j] != id)
					r++;
			}
			if (r == n)
				res++;

		}
		fres = max(fres, res);
	}
	cout << fres << endl;
	return 0;
}

