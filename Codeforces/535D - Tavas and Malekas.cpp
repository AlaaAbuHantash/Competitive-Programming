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

vector<int> bb;
int n ,k,x;
char s[1000005];
void calc() {
	bb.clear();
	int m = strlen(s);
	bb.resize(m + 2);
	int i = 0, j = -1;
	bb[0] = -1;
	while (i < m) {
		while (j >= 0 && s[i] != s[j])
			j = bb[j];
		i++;
		j++;
		bb[i] = j;
	}

}
bool f;
int vis[1000006];
void calc2(int xx){

	if ( xx==1){
		f = 1;
		return;
	}
	if (xx == 0||xx==-1)
		return;

	calc2(bb[xx]);
}
const int M = 1000000007;
int main() {
	//aaaa
	//freopen("A.txt", "rt", stdin);
	scanf("%d%d %s", &n, &k, &s);
	calc();

	bool can = 1; 
	for (int i = 0; i < k; ++i){
		scanf("%d", &x);
		vis[x] = 1;
	}

	int len = strlen(s);
	int c = 0; 
	int k = 0; 
	for (int i = 1; i <= n&&can; ++i){

		if (vis[i] == 1){
			if (k){
				f = 0;
				calc2(len - k + 1);
				if (!f)
					can = 0;
			}
			k = len - 1;
			vis[i] = 1;
		}
		else if (k)
			k--;
		else
			c++;
	}
	if (!can){puts("0"); return 0;}
	if (!c){ puts("1"); return 0; }
	long long res = 1; 
	for (int i = 0; i < c; i++)
		res = ((res%M)* (26%M))%M;
	cout << res << endl;
		
		return 0;
}

