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
	long long a, b, n;
	cin >> a >> b >> n; 
	if (a >= n || b >= n)
		puts("0");
	else if (a <= 0 && b <= 0)
		puts("-1");
	else if(a >=0 && b>=0){
		long long c = 0;
		while (a < n && b < n){
			long long  x = min(a, b);
			long long y = max(a, b);
			a = y; 
			b = x + y;
			c++;
		}
		cout << c << endl;
	}
	else {
		long long c = 0;
		long long  xx = min(a, b);
		long long yy = max(a, b);
		long long r =  xx/yy; 
		//cout << r << endl;
		xx += (-r)*yy; 
		c -= r;
		a = xx;
		b = yy;
		//cout <<r << " " << a << " " << b << endl;
		while (a < n && b < n){
			long long  x = min(a, b);
			long long y = max(a, b);
			a = y;
			b = x + y;
			c++;
		}
		cout << c << endl;
		

	}
}

