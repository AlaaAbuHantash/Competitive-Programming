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
const int N = 1e5;
int l[N + 100], R[N + 100];
int main() {
	//freopen("test.txt", "rt", stdin);
	int n, x;
	vector<int > v, vv;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x;
		v.push_back(x);
		vv.push_back(x);
	}
	int res = 1;
	int r = 1;
	l[0] = 1;
	for (int i = 0; i < n - 1; i++){
		if (v[i] < v[i + 1])
			r++;
		else
			r = 1;
		l[i + 1] = r;
	}


	r = 1;
	R[n-1] = 1;
	for (int i = n - 2; i >= 0; i--){
		if (v[i +1] > v[i])
			r++;
		else
			r = 1;
		R[i] = r;
		//cout << v[i + 1] << " " << v[i] << " " << i << " " << r << endl;
	}


	//for (int i = 0; i < n; i++)
		//cout << v[i] << " " << l[i] << " " << R[i] << endl;


	for (int i = 0; i < n; i++){

		int rr = R[i+1], ll = 0;
		
		int nub1, nub2; 
		if (i - 1 >= 0){
			nub1 = v[i - 1];
			ll = l[i-1];
			res = max(res, ll + 1);
		}
		else
			nub1 = 0;

		if (i + 1 < n){
			nub2 = v[i + 1];
			res = max(res, rr + 1);
		}
		else{
			nub2 = nub1 + 3,rr=0;
			
		}
		//cout << nub1 << " " << nub2 << endl;
		if (nub2-nub1>=2)
			res = max(res, ll + rr+1 );
		
	}

	//if (n == 1)
	//	res--;
	cout << res << endl;
}
