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
#include <stdio.h>
#include <fstream>
#define mp make_pair
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int main() {

	//freopen("test.txt", "rt", stdin);
	//freopen("myfile.txt", "w", stdout);
	string s,res="";
	cin >> s; 

	int i; 
	for (i = 0; i < s.length() ; i++){

		if (i + 2 <  s.length() && s[i] == s[i + 1] && s[i + 2] == s[i + 1]){
			res += s[i];
			res += s[i];
			char ch = s[i];
			while (i < s.length() && s[i] == ch)
				i++;
			i--;
		}
		else
			res += s[i];
	}
	int k = 0;
	string g = "";
	for (; k < res.length() && k < 3; k++)
		g += res[k];

	k = 0;
	for (int j = 3; j < res.length(); j++){
		if (g[k] == g[k + 1] && g[k+2] == res[j])
			continue;
		else {
			g += res[j];
			k++;
		}
	}
	cout << g << endl;
}