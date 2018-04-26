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
int a[100005];
int fr[100005];
int main()
{
	//freopen("test.txt", "rt", stdin);

	int n, k, x;
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	bool f = 0;
	int c = 0, st = 0; 
	for (int i = 0; i < n; i++){
		fr[a[i]]++;
		if (fr[a[i]] == 1)
			c++;
		while (fr[a[st]] > 1){
			fr[a[st]]--;
			st++;
		}
		if (c == k){
			f = 1; 
			printf("%d %d", st + 1, i + 1);
			break;
		}
	}
	if (!f)
		puts("-1 -1");
	return 0;
}
