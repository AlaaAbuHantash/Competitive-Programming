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
map <string, int > ma; 
int a[105], c[105];
int main() {

	//freopen("test.txt", "rt", stdin);
	int n, m, x=1;
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> c[i];
	sort(c, c + n);

	for (int i = 0; i < m; i++){
		cin >> s;
		if (ma[s] == 0)
			ma[s] = x++;
		a[ma[s]-1]++;
	}
	x--;
	sort(a, a + x);

	int sum = 0;
	for (int i = 0; i < x; i++){
		sum += (a[x-i-1] * c[i]);
	}
	cout << sum << " "; 
	sum = 0;
	for (int i = x-1, j = n - 1; i >=0 ; i--, j--)
		sum += (a[i] * c[j]);
	cout << sum << endl;
	return 0;
}