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
string s; int n, k; 
int main() {
//	freopen("text.txt", "rt", stdin);
	cin >> n >> k >> s;
	int take = -1, pos; 
	for (int i = n - 1; i >= 0; i--){
		for (int j = s[i] - 'a' + 1; j < k; j++){
			if (i - 2 >= 0){
				if (j != s[i - 1] - 'a' && j != s[i - 2] - 'a'){
					take = j;
					s[i] = j + 'a';
					pos = i;
					break;
				}
			}
			else if (i - 1 >= 0){
				if (j != s[i - 1] - 'a'){
					take = j;
					s[i] = j + 'a';
					pos = i;
					break;
				}
			}
			else {
				take = j;
				s[i] = j + 'a';
				pos = i;
				break;
			}
		}
		if (take != -1)
			break;
	}
	if (take == -1)
		puts("NO");
	else {
		for (int i = pos+1; i < n; i++){
			bool f = 0; 
			if (i - 2 >= 0){
				for (int j = 0; j < k; j++){
					if (j != s[i - 1] - 'a' && j != s[i - 2] - 'a'){
						s[i] = j + 'a';
						f = 1;
						break;
					}
				}
				if (!f)
				{
					puts("NO");
					return 0;
				}
			}
			else if (i - 1 >= 0){
				for (int j = 0; j < k; j++)
					if (s[i - 1]-'a' != j){
						s[i] = j + 'a';
						f = 1;
						break;
					}

				if (!f)
				{
					puts("NO");
					return 0;
				}
			}
		}

		cout << s << endl;

	}
	return 0;
}