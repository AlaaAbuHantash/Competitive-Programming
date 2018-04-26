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
string s;
int main() {

	//freopen("test.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> s;
	int c = 0,f=0,a=0,b=0,y=1;
	vector<int > v;
	for (int i = s.length() - 1; i >= 0&&y; i--){
		if (f){
			if (s[i] == ')')
				c++;
			else if (s[i] == '('){
				if (c>0)
					c--;
				else
					b++;
			}
		}
		if (s[i] == '#'){
			if (f){
				if (b == 0)
					b = 1,c++;
				v.push_back(b);
			}
			b = 0;
			f = 1;
		}
		else if (s[i] == ')'&&!f)
			c++;
		else if (s[i] == '('&&!f){
			if (c>0)
				c--;
			else
				y = 0;
		}
	}

	//cout << c << b <<  endl;
	if (y&& c == 0 && b){
		v.push_back(b);
		for (int i = v.size() - 1; i >= 0; i--)
			cout << v[i] << endl;
	}
	else
		puts("-1");
	return 0;
}

