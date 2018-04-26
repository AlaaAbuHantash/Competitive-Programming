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
	//freopen("myfile.txt", "w", stdout);
	int n, d, x; 
	vector<int > v; 
	cin >> n >> d; 
	for (int i = 0; i < n; i++){
		cin >> x;
		v.push_back(x);
	}
	
	long long res = 0; 
	for (int i = 0; i < n; i++){
		int x = v[i] + d; 
		int ind = lower_bound(v.begin(), v.end(), x) - v.begin();
		//cout << ind << endl;
		if (ind<n && v[ind] > x)
			ind--;
		if (ind == n)
			ind--;
		//cout << v[i] << " " << ind << endl;
		if (ind - i >= 2){
			long long  xx = ind - i; 
			res += (long long)xx*(long long)(xx - 1) / 2;
		}

	}
	cout << res << endl;
}