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
#include <stdio.h>
#include <fstream>
#define mp make_pair
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int vis[100005];
bool ck(int nub){
	//cout << nub << endl;
	if (vis[nub])
		return 0;
	vis[nub] = 1;
	int sum = 0;
	while (nub != 0){
		sum += (nub % 10)*(nub % 10);
		nub /= 10;
	}
	if (sum == 1)
		return true; 
	return ck(sum);
}

const int N = 100000;
bool isprime[N+10];

void prime() {

	memset(isprime, true, sizeof(isprime));

	isprime[0] = isprime[1] = false;
	for (int i = 2; i *i <= N; i++)
		if (isprime[i]){
			for (int j = i * i; j <= N; j += i)
				isprime[j] = false;
			//cout << i << endl;
		}

}
int main() {
//	freopen("test.txt", "rt", stdin);
	int t, n, g;
	
	prime();
	cin >> t;
	while (t--){
		cin >> g >> n;
		bool f = 0;
		memset(vis, 0, sizeof(vis));
		if (isprime[n] && ck(n))
			f = 1;
		printf("%d %d ", g, n);
		if (f)
			puts("YES");
		else
			puts("NO");
	}
}

