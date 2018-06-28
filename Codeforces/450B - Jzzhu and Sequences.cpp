#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<map>
using namespace std;
#define eps 1e-9
#define mp make_pair
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int a, b, c;
int main() {
	//freopen("input", "rt", stdin);
	cin >> a >> b >> c;
	vector<int> v;

	v.push_back(a);
	v.push_back(b);
	v.push_back(b - a);
	v.push_back(-a);
	v.push_back(-b);
	v.push_back(a - b);
	c--;
	cout << ((v[c % 6] % 1000000007) + 1000000007) % 1000000007 << "\n";
	return 0;
}

