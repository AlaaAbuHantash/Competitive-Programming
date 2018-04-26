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
int a[1000005];
int main() {
	//freopen("text.txt", "rt", stdin);
	int n, x;
	cin >> n;
	vector<int > v, vv;
	for (int i = 0; i < n; i++){
		cin >> x;
		v.push_back(x);
		vv.push_back(x);
	}
	sort(v.begin(), v.end());
	sort(vv.rbegin(), vv.rend());
	int res = 0, nub = 0;
	int z = n / 2 + (n & 1 ? 1 : 0), k=z-1;
	//cout << k << endl;
	for (int i = 0; i < z; i++){
		int x = vv[i] / 2;
		
		bool f = 0;
		while (k>=0 && !a[n-i-1]){
			if (v[k] <= x && !a[k]){
				f = 1;
				a[k] = 1;
				k--;
				break;
			}
			else {
				a[k] = 1; 
				k--;
			}
		}
		a[n - i - 1] = 1;
		if (f)
			nub += 2;
		else
			nub++;
		res++;
	}
	//cout << res << " " << nub << endl;
	cout << res + n - nub << endl;
	return 0;
}