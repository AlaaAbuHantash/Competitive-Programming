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
const int M = 10001;
int main()
{

	
	//freopen("test.txt", "rt", stdin);

	int n, x; 

	cin >> n; 
	vector<int > v;
	for (int i = 0; i < n; i++){
		cin >> x; 
		v.push_back(x);
	}

	for (int i = 0; i <= 10000; i++){
		for (int j = 0; j <= 10000; j++){
			int beg = v[0];
			bool f = 1; 
			for (int k = 0; k < n; k++){
				if (beg != v[k]){
					f = 0;
					break;
				}
				beg = ((i *v[k]) + j) % M;
				beg = ((i *beg) + j) % M;
			}
			if (f){
				for (int k = 0; k < n; k++){
					beg = ((i *v[k]) + j) % M;
					cout << beg << endl;;

				}
				return 0; 
			}

		}
	}
	return 0;
}
