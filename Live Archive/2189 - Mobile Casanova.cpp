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
#define mp make_pair
int main() {

	//freopen("test.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);
	int n,t=1; 
	while (scanf("%d", &n) > 0){
		if (!n)
			break;
		vector<string>v;
		printf("Case %d:\n", t++);
		for (int i = 0; i < n; i++){
			string s;
			cin >> s;
			v.push_back(s);
		}
		int beg = 0,c=0;
		for (int i = 1; i < n; i++){
			if (atoi(v[i - 1].c_str()) + 1 == atoi(v[i].c_str())){
				c++;
			}
			else{
				int j;
				for (j = 0; j < v[beg].length(); j++){
					if (v[beg][j] == v[i - 1][j])
						printf("%c", v[beg][j]);
					else
						break;
				}
				for (int k = j; k < v[beg].length(); k++)
						printf("%c", v[beg][k]);
				if (c){
					printf("-");
					for (int k = j; k < v[beg].length(); k++)
						printf("%c", v[i-1][k]);
				}
				c = 0;
				beg = i;
				puts("");
			}

		}
		int j=0;
		for (j = 0; j < v[beg].length(); j++){
			if (v[beg][j] == v[beg+c][j])
				printf("%c", v[beg][j]);
			else
				break;
		}
		for (int k = j; k < v[beg].length(); k++)
			printf("%c", v[beg][k]);
		if (c){
			printf("-");
			for (int k = j; k < v[beg].length(); k++)
				printf("%c", v[beg+c][k]);
		}
		puts("");
		c = 0;
		puts("");
	}
	return 0;
}

