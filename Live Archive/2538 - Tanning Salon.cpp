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
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
const int M = 1e9 + 7;
int a[33];
int main() {

	//freopen("test.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);

	int n; 
	string s;
	while (cin >> n){
		if (!n)
			break;
		cin >> s;
		memset(a, 0, sizeof(a));
		int len = s.length(),c=0,res=0,all=0;
		for (int i = 0; i < len; i++){
			if (a[s[i] - 'A'] == 0 && c < n){
				c++, a[s[i] - 'A']++, res++;
				all++;
			}
			else if (a[s[i] - 'A'] == 0)
				a[s[i] - 'A'] = 2,all++; 
			else if (a[s[i] - 'A'] == 1)
				c--;

		}
		//cout << res << endl;
		if (res == all)
			puts("All customers tanned successfully.");
		else
			printf("%d customer(s) walked away.\n", all - res);
	}

	return 0;
}

