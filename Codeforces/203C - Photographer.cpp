#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
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
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int main() {

	//freopen("a.txt", "rt", stdin);
	int n, d, a, b, x, y;
	cin >> n >> d >> a >> b;
	vector<pair<long long, int> > v;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		long long sum = x * a + y * b;
		v.push_back( mp(sum, i));
	}
	sort(v.begin(),v.end());
	int c = 0 ;
	for ( int i = 0 ; i < n;i++){
		if(d - v[i].first >=0 )
			d-=v[i].first,c++;
		else
			break;
	}
	cout << c << endl;
	for ( int i = 0 ; i < c ; i++)
		cout << v[i].second+1 << " " ;
	return 0;

}

