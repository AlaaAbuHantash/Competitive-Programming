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
	int a=0, b=0, x, y;
	cin >> x >> y;
	string s; 
	cin >> s;
	int f = 0;
	if (x == 0 && y == 0)
		f = 1;
	for (int i = 0; i < s.length()&&!f; i++){
		if (s[i] == 'U')
			b++;
		else if (s[i] == 'D')
			b--;
		else if (s[i] == 'L')
			a--;
		else
			a++;
		if (a == x&&y == b)
			f = 1;
	}
	int aa = x, bb = y;
	vector<pair<int, int> >v;
	v.push_back(mp(aa, bb));
	for (int i = 0; i <s.length() &&!f; i++){
		if (s[i] == 'U')
			bb--;
		else if (s[i] == 'D')
			bb++;
		else if (s[i] == 'L')
			aa++;
		else
			aa--;
		v.push_back(mp(aa, bb));
		//cout << aa << " " << bb << endl;
	}
	for (int i = 0; i < v.size()&&!f; i++){
		int xx = v[i].first;
		int yy = v[i].second;
		//cout << xx << " " << x << " " << a << "  " << yy << " " << y << " " << b << endl;
		if (xx == 0){
			if (a==0 && b &&yy&& yy/b>=0 && ((yy%b) + b) % b == 0)
				f = 1;
		}
		else if (yy == 0){
			if (b==0&&a&&xx&&xx/a >= 0 && ((xx%a) + a) % a == 0)
				f = 1;
		}
		else if (a&&b&&((xx%a)+a)%a == 0 && ((yy%b)+b)%b == 0 && xx *b == yy*a && xx/a>=0)
			f = 1;
	}
	
	if (f)
		puts("Yes");
	else
		puts("No"); 
	return 0;
}

