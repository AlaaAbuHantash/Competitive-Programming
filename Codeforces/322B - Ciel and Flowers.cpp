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
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int a, b, c;
int main() {

	//freopen("test.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> a >> b >> c; 
	long long res = 0;
	int r = 0,rr=0;
	if (a % 3 == 0)r++;
	if (b % 3 == 0)r++;
	if (c % 3 == 0)r++;

	if (a % 3 == 2)rr++;
	if (b % 3 == 2)rr++;
	if (c % 3 == 2)rr++;
	if (r>=2)
		res = a / 3 + b / 3 + c / 3;
	else if (rr>=2 && (a >= 2 && b >= 2 && c >= 2)){
			a -= 2, b -= 2, c -= 2;
			res += 2;
			res+= a / 3 + b / 3 + c / 3;
	}
	else {
		if (a >= 1 && b >= 1 && c >= 1){
			a -= 1, b -= 1, c -= 1;
			res += 1;
			res += a / 3 + b / 3 + c / 3;
		}
		else 
			res += a / 3 + b / 3 + c / 3;
	}
	cout << res << endl;
	return 0;
}

