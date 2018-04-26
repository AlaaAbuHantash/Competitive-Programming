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

int  main(){
	string s; 
	cin >> s; 
	int c = 1;
	long long res = 1;
	for (int i = 1; i < s.length(); i++){
		int x = s[i] - 2 * '0' + s[i - 1];
		if (x == 9){
			c++;
		}
		else {
			if (c%2&&c/2)res *= c/2+1;
			c = 1;
		}
	}
	if (c % 2 && c / 2)res *= c/2 + 1;
	cout << res << endl;
	return 0;
}