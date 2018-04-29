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
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int main() {
	//freopen("test.txt", "rt", stdin);

	string s;
	cin >> s;
	int x = s.find('.');
	if (s[x - 1] == '9')
		puts("GOTO Vasilisa.");
	else {
		if (s[x + 1] >= '5')
			s[x - 1]++;
		s = s.substr(0, x);
		cout << s << endl;
	}
	return 0;
}

