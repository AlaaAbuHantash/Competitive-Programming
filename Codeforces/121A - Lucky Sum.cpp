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
vector<long long> v;
void calc(long long n) {

	if (n > 1e10)
		return;
	v.push_back(n);
	calc(n * 10 + 4);
	calc(n * 10 + 7);

	return;

}
int main() {

	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);
	calc(0);
	sort(v.begin(), v.end());
	long long a, b;
	cin >> a >> b;
	int y = lower_bound(v.begin(), v.end(), a) - v.begin();
	int z = lower_bound(v.begin(), v.end(), b) - v.begin();

	long long sum = (v[y] - a + 1) * v[y];
	//cout << sum << endl;
	for (int i = y+1; i <= z; i++) {
		sum+= (v[i]-v[i-1])*v[i];
		//cout << v[i-1] <<  " " << v[i] << endl;
	}
	sum-=(v[z]-b)*v[z];
	cout << sum << endl;
	return 0;
}

