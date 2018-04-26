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

vector<int > v;
int n; 
void calc(int x){

	if (x > n)
		return;

	v.push_back(x);
	calc(x * 10);
	if (x%10!=1)
		calc(x+1);
}
int main() {

	int t = 1;
	//freopen("test.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	calc(1);
	cout << v.size() << endl;
	return 0;
}

