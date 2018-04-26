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
int c[100005];
int main() {
	//	freopen("text.txt", "rt", stdin);
	int a, b; 
	cin >> a >> b;
	if (a == b)
		puts("infinity");
	else {
		int res = 0, nub = a - b;
		for (int i = 1; i*i <= nub; i++){
			if (nub%i == 0){
				if (i>b)
					res++;
				if (i*i != nub&&nub/i>b)
					res++;
			}
		}
		cout << res << endl;
	}

	return 0;
}