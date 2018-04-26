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
#define mp make_pair

int main() {

	//freopen("test.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);
	long long  a, b, c; 
	cin >> a >> b >> c; 
	a--, b--;
	int aa = a/c; 
	int bb = b/c;
	aa++, bb++;
	//cout << aa << " " << bb << endl;
	if (a%c != 0)aa *= a % c + 1;
	if (b%c != 0)bb *= b % c + 1;
	cout << (long long)aa*(long long)bb << endl;
	return 0;
}

