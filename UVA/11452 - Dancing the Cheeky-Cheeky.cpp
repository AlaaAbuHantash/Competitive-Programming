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
string s, tmp;
int  main()
{
	//freopen("A.txt", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);

	int t;
	scanf("%d", &t);
	while (t--){

		cin >> s;

		int len = s.length();
		for (int i = 1; i < len; ++i){
			tmp = s.substr(0, i);

			int k = 0,j=i; 
			while (s[j] == tmp[k]){
				j++, k++;
				if (k == i)
					k = 0;
			}
			if (j == len){

				//12312312...
				j = 8; 
				while (j--){
					printf("%c", tmp[k]);
					k++;
					if (k == i)
						k = 0;
				}
				puts("...");
				break;
			}
		}
	}
	return 0;
}