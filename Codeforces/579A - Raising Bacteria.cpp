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
#define mp make_pair
const int N = 1e5; 
vector<long long  > v; 
int n;

int  main(){
	//freopen("test.txt", "rt", stdin);
	
	long long sum = 1;
	for (int i = 0; i <30; i++){
		sum = sum * 2; 
		v.push_back(sum);
	}
	cin >> n;
	int res = 0;
	if (n % 2 == 1)
		res++, n--;

	int x = v.size() - 1; 
	while (n){
		while(v[x]>n)
			x--;
		while (v[x] <= n){
			n -= v[x];
			res++;
		}
		x--;
	}
	cout <<res<<endl;

	return 0;
}