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
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int GCD(int a, int b)
{
	if (a%b == 0) return b;
	return GCD(b, a%b);
}
int main() {
	//freopen("test.txt", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);
	int a,n,mx=0;
	bool f = 0; 
	cin >> n;
	cin >> a;
	mx = max(a, mx);
	int gcd = a;
	for (int i = 1; i < n; i++){
		cin >> a;
		mx = max(a, mx);
		if (a % 2 == 1)
			f = 1;
		gcd = GCD(gcd, a);
	}
	long long nub = mx;
	if (!f) 
		nub /= gcd;
	
	nub -= n;

	if (nub % 2)
		puts("Alice");
	else
		puts("Bob");

	return 0;
}