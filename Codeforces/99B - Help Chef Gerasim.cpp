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
#define mp make_pair
#define eps 1e-6
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int ma[10005];
int c;
pair < int, int > vv[10001];
int main() {
	//freopen("test.txt", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);

	int n, x; 
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &x);
		vv[i]=mp(x,i+1);
		if (!ma[x])
			c++;
		ma[x]++;
	}
	
	sort(vv, vv+n);
	
	if (c == 1)
		puts("Exemplary pages.");
	else if (c== 2 && n == 2 ){
		int x = vv[1].first - vv[0].first;
		if (x % 2 == 0 )
			printf("%d ml. from cup #%d to cup #%d.\n", x / 2, vv[0].second, vv[1].second);
		else 
			puts("Unrecoverable configuration.");
	}
	else if (c== 3){
	
		if (ma[vv[0].first] == 1  && ma[vv[n - 1].first] == 1){
			int x = vv[n - 1].first - vv[1].first;
		
			if (vv[0].first + x == vv[1].first)
				printf("%d ml. from cup #%d to cup #%d.\n", x, vv[0].second, vv[n - 1].second);
			else
				puts("Unrecoverable configuration.");

		}
		else
			puts("Unrecoverable configuration.");
	}
	else 
		puts("Unrecoverable configuration.");
	
	return 0; 
}