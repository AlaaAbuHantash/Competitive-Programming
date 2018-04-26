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
#define mp make_pair
#define eps 1e-6
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int n, m ,a , b ; 
int main() {
	//freopen("text.txt", "rt", stdin);
	cin >> n >> m;
	vector<int > res(n);
	int aa, bb; 
	for (int i = 0; i < m; i++){
		cin >> a >> b; 
		for (int j = 0; j < n; j++){
			cin >> aa >> bb; 
			if ((a > b && aa > bb) || (b > a && bb > aa) || (a==b && bb==aa))
				res[j] += 2;
			
			if (a - b == aa - bb)
				res[j] += 3;

			if (a == aa)
				res[j]++;
			if (b == bb)
				res[j]++;
		}
	}
	printf("%d", res[0]);
	for (int j = 1; j < n; j++)
		printf(" %d", res[j]);
	puts("");
	return 0;
}
