#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip> 
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
#define mp make_pair
string s;
const int N = 3e5;
int v[N + 10], p[N + 10], t[N + 10];
int m; 
vector<string > ss(3);
void fun(){
	int i = 0, j = -1; v[0] = -1; 
	while (i < m){
		while (j >= 0 && s[i] != s[j]) j = v[j];
		i++, j++;
		v[i] = j;
	}
}
int  main(){
	//freopen("test.txt", "rt", stdin);
	cin >> ss[0] >> ss[1] >> ss[2];
	string tmp = "012";
	int res = ss[0].length() + ss[1].length() + ss[2].length();
	do{
		int a = tmp[0] - '0';
		int b = tmp[1] - '0';
		int c = tmp[2] - '0';
		s = ss[b] + "&" + ss[a];
		
		m = s.length();
		fun();
		bool ff = 0;
		for (int i = ss[b].length(); i < m&&!ff; i++){
			if (v[i + 1] == ss[b].length())
				ff = 1;
		}
		string tt="";
		if (!ff)
			tt = ss[a] + ss[b].substr(v[m]);
		else
			tt = ss[a];

		s = ss[c] + "&" + tt;
		m = s.length();
		fun();
		ff = 0;
		for (int i = ss[c].length(); i < m &&!ff; i++)
			if (v[i + 1] == ss[c].length())
				ff = 1;
		

		string ttt = "";
		if (!ff)
			ttt = tt + ss[c].substr(v[m]);
		else
			ttt = tt;

		res = min(res, (int)ttt.length());

	} while (next_permutation(tmp.begin(), tmp.end()));
	cout << res << endl;
	return 0;
}