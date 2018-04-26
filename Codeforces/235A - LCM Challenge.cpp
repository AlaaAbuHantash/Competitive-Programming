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
int GCD(long long  a, long long  b)
{
	if (a%b == 0) return b;
	return GCD(b, a%b);

}


int main() {

	//freopen("test.txt", "rt", stdin);
	//freopen("myfile.txt", "w", stdout);

	long long n; 

	cin >> n; 
	if (n <= 2){
		cout << n << endl;
		return 0;
	}
	vector<long long> v; 
	v.push_back(n);
	v.push_back(n - 1);
	v.push_back(n - 2);

	if (n-3>0)
		v.push_back(n - 3);
	if (n-4>0)
		v.push_back(n - 4);
	if (n - 5>0)
		v.push_back(n - 5);

	int len = v.size();
	long long res = 0; 
	for (int i = 0; i < len; i++)
		for (int j = i+1; j < len; j++)
			for (int k = j + 1; k < len; k++){

				long long nub = v[i] * v[j] * v[k]; 
				long long gcd = GCD(v[i], v[j]);
				nub /= gcd;
				gcd = GCD(v[k], v[j]);
				nub /= gcd;
				gcd = GCD(v[i], v[k]);
				nub /= gcd;
				res = max(res, nub);
			}
	
	cout << res << endl;

}