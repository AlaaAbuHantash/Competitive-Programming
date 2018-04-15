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
string a, b; 
int n; 
string  dp[10002][102];
string sum(string aa, string bb){
	string rr; 
	
	if (aa.length() > bb.length())
		rr = "00" + aa;
	else
		rr = "00" + bb;
	int c = 0; 
	int beg = rr.size() - 1;
	int i = aa.length() - 1, j = bb.length() - 1;
	for (; i >= 0 && j >= 0; i--, j--) {

		int x = aa[i] - '0' + bb[j] - '0' + c;
		rr[beg] = char(x%10 + '0');
		c= x / 10;
		beg--;
	}

	if (aa.length() > bb.length()){
		for (; i >= 0; i--){
			int x = aa[i] - '0' + c;
			rr[beg] = char(x % 10 + '0');
			c = x / 10;
			beg--;
		}
	}
	else if ( aa.length() < bb.length() ) {
		for (; j >= 0; j--){
			int x = bb[j] - '0' + c;
			rr[beg] = char(x % 10 + '0');
			c = x / 10;
			beg--;
		}
	}
	if (c){
		rr[beg] = char(c % 10 + '0');
	}
	int k;
	for (k = 0; k < rr.size(); k++){
		if (rr[k] != '0')
			break;
	}
	
	rr = rr.erase(0, k);

	return rr;

}
string calc(int ind, int x ){
	
	if (x == b.size() && ind == a.size())
		return "1"; 
	if (x > b.size() || ind > a.size())
		return "0"; 
	string res = "0"; 
	if (dp[ind][x] != "#")
		return dp[ind][x];

	if (x < b.size() && a[ind] == b[x])
		res = sum ( res , calc(ind + 1, x + 1));
	res = sum ( calc(ind + 1, x) , res ) ;
	return dp[ind][x] = res;
}
int main() {
	//freopen("test.txt", "rt", stdin);
	scanf("%d", &n);
	while (n--){

		for (int i = 0; i < 10002; i++)
			for (int j = 0; j < 102; j++)
				dp[i][j] = "#";
		cin >> a >> b; 
		string r = calc(0, 0);
		cout << r << endl;
	}
	return 0;
}

