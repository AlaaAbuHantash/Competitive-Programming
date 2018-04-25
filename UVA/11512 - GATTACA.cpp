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
int res;
char s[1111];
char p[1111];
char p2[1111];
vector<vector<int > > v;
int len;
int ar[33];
vector<int > freq;
char ch[] = { 'A', 'C', 'G', 'T' };
int fr;
void calc(int x) {
	int cur = 0,r=0;
	for (int i = x; i < len; ++i){
		if (v[cur][ar[s[i] - 'A']] == -1){
			v.push_back(vector<int >(4, -1));
			v[cur][ar[s[i] - 'A']] = v.size() - 1;
			freq.push_back(0);
		}
		cur = v[cur][ar[s[i] - 'A']];
		freq[cur]++;
		if (freq[cur]>1)
			r++;
		if (r > res){
			res = r;
			fr = freq[cur];
		}
	}

}
int g, gg;
bool path(int x, int r){

	if (r == res){
		p[r] = NULL;
		g = gg;
		return true;
	}
	for (int i = 0; i < 4; i++){
		if (v[x][i] != -1 && freq[v[x][i]] >= fr){
			p[r] = ch[i];
			gg = freq[v[x][i]];
			if (path(v[x][i], r + 1))
				return true;
			p[r] = NULL;
		}
	}
	return false;
}
int  main()
{
	ar[0] = 0;
	ar['C' - 'A'] = 1;
	ar['G' - 'A'] = 2;
	ar['T' - 'A'] = 3;

	//freopen("A.txt", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);
	int t;
	scanf("%d", &t);
	while (t--){
		v.clear();
		v.push_back(vector<int >(4, -1));
		freq.clear();
		freq.push_back(0);
		scanf("%s", s);
		len = strlen(s);
		res = 0;
		fr = 0;
		for (int i = 0; i <len ; ++i)
			calc(i);


		path(0, 0);
		if (res >= 1)
			printf("%s %d\n",p, g);
		else
			puts("No repetitions found!");
		for (int i = 0; i <=len; ++i)
			p[i] = NULL;
	}

	return 0;
}