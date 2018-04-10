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
int dx[] = { -1, 0, 0, 1, 1, 1, -1, -1 };
int dy[] = { 0, -1, 1, 0, 1, -1, 1, -1 };
int main() {
	string a, b;
	cin >> a >> b;
	if (a.length() > b.length())
		for (int i = b.length(); i < a.length(); i++)
			b = "0" + b;
	else if (a.length() < b.length())
		for (int i = a.length(); i < b.length(); i++)
			a = "0" + a;

	a = "000" + a;
	b = "000" + b;
	string res = a;
	int c = 0;
	for (int i = a.length() - 1; i >= 0; i--) {
		int x = a[i] + b[i] - (2 * '0') + c;
		if (x >= 10)
			c = x / 10;
		else
			c = 0;
		res[i] = char(x % 10 + '0');
	}
	string tmp = res;
	for (int i = 0; i < res.length(); i++)
		if (res[i] == '0')
			tmp.erase(0, 1);
		else
			break;
	cout << tmp << endl;
	return 0;
}

