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
long long  a[100005];
int main() {
	//freopen("text.txt", "rt", stdin);
	int n, m ;
	long long ad = 0,val; 
	cin >> n >> m; 
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int w, pos; 
	for (int i = 0; i < m; i++){
		cin >> w; 
		if (w == 1){
			cin >> pos >> val; 
			a[pos-1] = val - ad;
		}
		else if (w == 2){
			cin >> val; 
			ad += val;
		}
		else {
			cin >> pos; 
			cout << a[pos - 1]+ad << endl;
		}
	
	}
	return 0;
}