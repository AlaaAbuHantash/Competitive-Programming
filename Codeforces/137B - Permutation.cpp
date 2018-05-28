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
int dx[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
int dy[] = { 0, 1, 0, -1, -1, -1, 1, 1 };
#define mp make_pair
int a, b, c;
int main() {
	//freopen("test.txt", "rt", stdin);
	scanf("%d", &a);
	set<int> v;
	for (int i = 0; i < a; i++) {
		scanf("%d", &b);
		if (b <= a)
			v.insert(b);
	}
	printf("%d\n", a - v.size());
	return 0;
}


