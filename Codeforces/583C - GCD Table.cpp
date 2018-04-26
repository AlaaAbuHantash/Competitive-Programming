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
map<int, int > m;
int vis[500 * 500 + 50];
int GCD(int a, int b){
	if (a%b == 0)
		return b;
	return GCD(b, a%b);
}
int main() {
	//freopen("test.txt", "rt", stdin);
	int n, a; 
	cin >> n; 
	vector<int > v; 
	for (int i = 0; i < n*n; i++){
		cin >> a; 
		v.push_back(a);
		m[a]++;
	}
	sort(v.rbegin(), v.rend());

	vector < int > res; 
	res.push_back(v[0]);
	m[v[0]]--;
	vis[0] = 1;
	for (int i = 1; i < v.size(); i++){
		if (m[v[i]]){
			vis[i] = 1;
			res.push_back(v[i]);
		}
		else
			continue;
		m[v[i]]--;
		for (int j = 0; j < i; j++){
			if (!vis[j])
				continue;
			int gcd = GCD(v[i], v[j]);
			m[gcd] -= 2;
		}
	}
	for (int i = 0; i < n; i++)
		cout << res[i] << " ";
	return 0;
}
