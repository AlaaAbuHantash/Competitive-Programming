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
int main() {
	//freopen("text.txt", "rt", stdin);
	int n;
	while (scanf("%d", &n) > 0){
		if (!n)
			break; 
		vector<int > v; 
		int x; 
		int res=0, st = 0 , nub = 0 ,cnt =0 ; 
		for (int i = 0; i < n; i++){
			scanf("%d", &x);
			if (x){
				v.push_back(x);
				if (v.size() == 1 )
					res = x - 1;
			}
		}

		int sum = 0;
		bool f = 1; 
		if (v.size()){
			for (int i = 0; i < v.size(); i++){
				sum += v[i];
				cnt++;
				if (sum > res){
					res = sum;
					st = i;
					nub = cnt;
				}

				if (sum == res && !f){
					if (nub > cnt){
						st = i;
						nub = cnt;
					}
				}
				if (sum < 0){
					sum = 0;
					cnt = 0;
					f = 0;
				}
			}
			st = st - nub + 1;
			printf("%d", v[st]);
			for (int i = 1; i < nub; i++, st++){
				printf(" %d", v[st + 1]);
			}
			puts("");
		}
		else
			puts("0");
	}
	return 0;
}