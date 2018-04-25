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
string s;
vector < vector<int > > v;
map<int, bool > m;
void add() {
	int cur = 0;
	int len = s.length();
	for (int i = 0; i < len; ++i){
		if (v[cur][s[i] - 'a'] == -1){
			v.push_back(vector<int >(27, -1));
			v[cur][s[i] - 'a'] = v.size() - 1;
		}
		cur = v[cur][s[i] - 'a'];
	}
	m[cur] = 1;
}
bool ala;
char p[2500005] = "";
void print2(int x, int j, int g) {
	if (m[x] && g){
		ala = 1;
		p[j] = '\0';
		printf("%s\n", p);

	}
	for (int i = 0; i < 26; ++i){
		if (v[x][i] != -1){
			p[j] = char('a' + i);
			print2(v[x][i], j + 1, 1);
			p[j] = '\0';
		}
	}
}
void find2() {

	int cur = 0;
	int len = s.length();
	for (int i = 0; i < len; ++i){
		if (v[cur][s[i] - 'a'] == -1){
			puts("No match.");
			return;
		}
		cur = v[cur][s[i] - 'a'];
		p[i] = s[i];
	}

	print2(cur, len, 0);
	for (int i = 0; i < len + 2; ++i)
		p[i] = '\0';

	if (!ala)
		puts("No match.");
}
int  main()
{
	//freopen("A.txt", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);
	int n;
	v.clear();
	v.push_back(vector<int >(27, -1));
	scanf("%d", &n);
	while (n--){
		cin >> s;
		add();
	}
	scanf("%d", &n);
	int t = 1;
	while (n--){
		ala = 0;
		printf("Case #%d:\n", t++);
		cin >> s;
		find2();

	}
	return 0;
}