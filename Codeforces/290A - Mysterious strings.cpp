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
int main() {
	//freopen("test.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);
	string g[] = { "Washington", "Adams", "Jefferson", "Madison", "Monroe",
			"Adams", "Jackson", "Van Buren", "Harrison", "Tyler", "Polk", "Taylor",
			"Fillmore", "Pierce", "Buchanan", "Lincoln", "Johnson", "Grant",
			"Hayes", "Garfield", "Arthur", "Cleveland", "Harrison", "Cleveland",
			"McKinley", "Roosevelt", "Taft", "Wilson", "Harding", "Coolidge",
			"Hoover", "Roosevelt", "Truman", "Eisenhower", "Kennedy", "Johnson",
			"Nixon", "Ford", "Carter", "Reagan" };

	int n;
	cin >> n;
	cout << g[n - 1];
	return 0;
}

