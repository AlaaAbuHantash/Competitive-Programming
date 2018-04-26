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
#define eps 1e-6
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int main() {
	//freopen("a.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);
	int x ;
	cin >> x ;
	if(x%3 == 2)
		x+=2;
	int z = x/36;
	int xx =  x - z * 36 ;
	int g = xx / 3 ;
	cout << z << " " << g << endl;
	return 0;
}

