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
vector<string > v; 
int n,x; 
int main()
{
	//freopen("test.txt", "rt", stdin);
	cin >> n; 
	vector<int > v;
	for (int i = 0; i < n; i++){
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	vector<int > res;
	for (int i = 0; i < n; i++){

		bool g = 0;
		for (int j = 0; j < res.size()&&!g; j++){
			if (res[j] <= v[i]){
				res[j] ++;
				g = 1;
			}
		}
		if (!g) {
		
			res.push_back(1);
		}
	}
	cout << res.size() << endl;
	return 0;
}

