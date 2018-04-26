#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
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
set<pair <int , string> >v;
set<pair <int, string> >::iterator it;
void calc(string s , bool f ){
	if (s.length() > 200)
		return; 
	if (s.length())
	v.insert(make_pair(s.length(),s));
	if (f)
		calc(s + "6", f);
	else {
		calc(s + "8", 0);
		calc(s + "8", 1);
	}
}
int main() {


	string s = ""; 
	calc("", 0);
	calc("", 1);
	int t, n;
	cin >> t; 
	while (t--){
		bool f = 0;
		cin >> n; 
		for (it = v.begin(); it != v.end(); it++){
			s = (*it).second;
			int len = s.length(), res = 0;
			for (int i = 0; i < len; i++)
				res = (res * 10 + (s[i] - '0')) % n;

			if (res==0){
				printf("%s\n", s.c_str());
				f = 1;
				break;
			}
			if (f)
				break;
		}
		if (!f)
			puts("-1");
	}
	return 0;
}