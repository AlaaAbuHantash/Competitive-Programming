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
map<string, bool>m;
string s, tmp; 

bool calc(int a , int b , int c ){

	if (a == s.size() && b == tmp.size())
		return 1;
	if (a > s.size() || b > tmp.size())
		return 0; 

	int r = 0; 
	if (!c){
		r |=calc(a + 1, b, 1);
		r |= calc(a, b + 1, 1);
		r |= calc(a+1, b + 1, 1);
	}
	if (s[a] == tmp[b])
		r |= calc(a + 1, b + 1, c);
	return r; 
}
int  main()
{
	//freopen("A.txt" , "rt" , stdin);
	//freopen ("myfile.txt","w",stdout);
	int t, f=0; 
	scanf("%d", &t);
	while (t--){
		m.clear();
		if (f)
			puts("");
		f = 1;
		vector<string >v;
		while (cin >> s&&s != "#")
			v.push_back(s),m[s]=1;

		int len = v.size();
		while (cin >> s && s != "#"){
			cout << s;
			if (m[s])
				puts(" is correct");
			else {
				printf(":");
				for (int i = 0; i < len; i++){
					tmp = v[i];
					int z = tmp.size() - s.size();
					if (abs(z) > 1)
						continue;
					if (calc(0, 0, 0))
						cout << " " << v[i];

				}
				puts("");
			}

		}
	}
	return 0;
}