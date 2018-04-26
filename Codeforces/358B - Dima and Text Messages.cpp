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
vector<string > v; 
int n; 

int main()
{
	//freopen("test.txt", "rt", stdin);
	cin >> n; 
	while (n--){
		cin >> s; 
		v.push_back(s);

	}
	cin >> s; 
	int len = s.length();
	bool f = 1, g = 0, fres = 1; 
	int k = 0;
	for (int i = 0; i < len;){
		if (f){
			g = 0;
	
			while (i < len && s[i] != '<')
				i++;
			i++;
			while (i < len && s[i] != '3')
				i++;
		
			if (i < len && s[i] == '3')
				g = 1 ;
			i++;
			if (k == v.size())
				break;
	
		}
		else {
			if (g){
				int j = 0; 
				while (i < len && j < v[k].length()){
					if (s[i] == v[k][j])
						j++;
					i++;
				}
				if (j != v[k].length()){
					fres = 0;
					break;
				}
				else
					k++;
			}
			else{
				fres = 0; 
				break;
			}
			g = 0;
		}
		f = !f;
	}

	if (g && k == v.size() && fres)
		puts("yes");
	else
		puts("no");
	return 0;
}

