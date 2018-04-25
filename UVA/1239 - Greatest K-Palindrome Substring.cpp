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
#include<stdio.h>
#define mp make_pair
#define eps 1e-6

using namespace std;

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int  main()
{
	//freopen("A.txt" , "rt" , stdin);
	//freopen ("myfile.txt","w",stdout);
	int t, k; 
	string s; 
	scanf("%d", &t);
	while (t--){
		cin >> s >> k;
		int len = s.length();
		int res = -1;
		for (int i = 0; i < len; ++i){

			int l = i-1, r = i + 1 ,c=0,r2=1;
			while (1){
				if (l < 0 || r >= len||c>k)
					break;

				if (s[l] != s[r])
					c++;
				if (c > k)
					break;
				r2 += 2;
				l--, r++;
			}
			res = max(r2, res);
			l = i , r = i + 1, c = 0, r2 = 1;
			if (l < 0 || r >= len)
				continue;
			if (s[l] != s[r])
				c++;
			if (c > k)
				continue;
			r2++;
			l--, r++;
			while (1){
				if (l < 0 || r >= len || c>k)
					break;

				if (s[l] != s[r])
					c++;
				if (c > k)
					break;
				r2 += 2;
				l--, r++;
			}
			res = max(r2, res);

		}
		printf("%d\n", res);

	}
	return 0;
}