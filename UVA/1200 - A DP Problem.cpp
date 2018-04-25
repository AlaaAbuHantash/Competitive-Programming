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

		cin >> s;
		int a = 0, b = 0, nub=0,g=1;
		int len = s.length(); 
		bool f = 0,gg=0;
		for (int i = 0; i < len; ++i){
			if (s[i] >= '0' && s[i] <= '9'){
				nub = nub * 10 + s[i] - '0';
				gg = 1;

			}
			else if (s[i] == 'x'){
				if (!gg&&!nub )
					nub = 1;
		
				if (!g)
					nub = nub * -1; // cost me all the WA's
				if (f)
					a -= nub;
				else
					a += nub;
				nub = 0;
				gg = 0;
			}
			else if (s[i] == '+' || s[i] == '-' || s[i] == '='){
				if (f){
					if (g)
						b -= nub;
					else
						b += nub;
				}
				else{
					if (g)
						b += nub;
					else
						b -= nub;
				}
				g = 1;
				if (s[i] == '-')
					g = 0;
				if (s[i] == '=')
					f = 1;
				nub = 0;
				gg = 0;
			
			}

		}
		if (nub){
			if (g)
				b -= nub;
			else
				b += nub;
		}
		b = b*-1;
		//cout << b << " " << a << endl;
		int res = floor((double)b / (double)a);
		if (a == 0&&b!=0)
			puts("IMPOSSIBLE");
		else if (a == 0)
			puts("IDENTITY");
		else
			printf("%d\n", res);
		//cout << a << " " << b << endl;


	}
	return 0;
}