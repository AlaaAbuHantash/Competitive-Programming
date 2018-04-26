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
int a[100005], b[100005]; 

int aa[100005], bb[100005];
int main() {
	//freopen("text.txt", "rt", stdin);
	int n, s; 
	cin >> n >> s; 
	char ch; 
	int q, p; 
	vector<int > v,vv; 
	for (int i = 0; i < n; i++){
		cin >> ch >> p >> q; 
		if (ch == 'S'){
			if (!a[p]){
				a[p] = 1; 
				v.push_back(p);
				aa[p] = q;
			}
			else {
				aa[p]+= q;
			}
		}
		else {
			if (!b[p]){
				b[p] = 1;
				vv.push_back(p);
				bb[p] = q;
			}
			else
				bb[p] += q;
		}
	}

	sort(v.rbegin(), v.rend());
	sort(vv.rbegin(), vv.rend());
	vector<int > tmp; 
	for (int i = v.size()-1, k = 0; k < s && i >= 0; i--, k++)
		tmp.push_back(v[i]);

	for (int i = tmp.size()-1; i >=0; i-- )
		printf("S %d %d\n", tmp[i], aa[tmp[i]]);

	for (int i = 0, k = 0; k < s && i < vv.size(); i++, k++)
		printf("B %d %d\n", vv[i], bb[vv[i]]);
	return 0;
}

