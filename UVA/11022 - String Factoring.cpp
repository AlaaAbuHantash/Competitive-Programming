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
int dp[88][88];
int len2;
char s[88];
int calc(int l, int r){

	//cout << l << " " << r << endl;
	if (l == r)
		return 1;
	if (l > r)
		return 0;
	if (dp[l][r] != -1)
		return dp[l][r];
	int res = len2; 
	for (int i = l; i < r; i++)
		res = min(res, calc(l, i) + calc(i + 1, r));

	int len = r - l + 1;
	for (int i = 1; i <= len; i++){
		if (len%i == 0){

			int st = l, c = i, j = l+i,cnt=0;
			if (j<=r)
			while (s[st] == s[j]){
				st++;
				j++;
				c--;
				if (c == 0){
					c = i;
					cnt++;
					st = l;
				}
				if (j > r)
					break;	
			}
			if (cnt*i == len-i && cnt && r!=l+1-i)
				res = min(res, calc(l, l + i - 1));

		}
	}
	return dp[l][r] = res;
}
int  main()
{
	//freopen("A.txt", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);
	while (scanf("%s", s) && s[0] != '*'){
		memset(dp, -1, sizeof(dp));
		len2 = strlen(s);
		int res = calc(0, len2 - 1);
		printf("%d\n", res);
	}
	return 0;
}