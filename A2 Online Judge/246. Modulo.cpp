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
/*  You got a dream, you gotta protect it.*/

using namespace std;
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int ind[20005];
int main() {
	//freopen("test.txt", "rt", stdin);
	int x, t;
	scanf("%d", &t);
	while (t--) {
		set<int> st;
		for (int i = 0; i < 10; i++) {
			scanf("%d", &x);
			st.insert(x % 42);
		}
		printf("%d\n", st.size());
	}
	return 0;
}

