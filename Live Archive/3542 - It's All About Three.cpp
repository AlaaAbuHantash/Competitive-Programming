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
const int N = 1e6;
int isp[N+10];
void p(){
	memset(isp, 1, sizeof(isp));
	isp[0] = isp[1] = 0;
	for (int i = 2; i*i <= N; ++i){
		if (isp[i])
			for (int j = i*i; j <= N; j += i)
				isp[j] = false;
	}
}
int main() {

	//freopen("test.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);
	int n; 
	p();
	while (cin >> n){
		if (n == -1)
			return 0; 
		bool f = 1; 
		for (int i = 1; i *i <= n&&f; i++)
			if (n%i==0){
				int lst = i % 10;
				if (lst != 3 && isp[i])
					f = 0;
				lst = (n / i) % 10;
				if (lst != 3 && isp[n/i])
					f = 0;
		}
		if (f) printf("%d YES\n",n);
		else printf("%d NO\n", n);
	}
	return 0;
}

