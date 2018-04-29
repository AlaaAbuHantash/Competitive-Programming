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
map<int, long long > m;
map<int, long long >::iterator it;
int main() {
	string s;
	unsigned long long sum = 0;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		m[s[i]]++;
	for (it = m.begin(); it != m.end(); it++)
		sum += (long long) (it->second * it->second);
	cout << sum << "\n";
	return 0;
}

