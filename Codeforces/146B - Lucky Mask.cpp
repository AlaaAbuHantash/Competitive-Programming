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
string b, tmp;
int a; 
int main()
{

	
	//freopen("test.txt", "rt", stdin);
	cin >> a >> b; 
	
	while (true){
		a++;
		tmp = "";
		int x = a; 
		while (x){
			if (x % 10 == 4 || x % 10 == 7)
				tmp = char(x % 10 + '0') + tmp;
			x /= 10;
		}
		if (tmp == b){
			cout << a << endl;
			break;
		}
	}
	return 0;
}
