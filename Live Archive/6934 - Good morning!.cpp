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
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair
#define pi 2 * acos(0);
#define eps 1e-6

using namespace std;

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
vector<int > v;
int nub;
int a[8][8];
map < int, int > ma;
void calc(int x, int y){
	//cout << x << " " << y << endl;
	if (x == 4 && y == 3){

		if (nub <= 999 && !ma[nub])
			v.push_back(nub);
		ma[nub] = 1;
		return;
	}

	if (x > 4 || y > 3 || nub > 999)
		return;
	if (a[x][y] != -1){
		nub = nub * 10 + a[x][y];
		if (nub != 0)
			calc(x, y);
		calc(x + 1, y);
		calc(x, y + 1);
		nub /= 10;
	}

	calc(x + 1, y);
	calc(x, y + 1);

}
int  main()
{
	//freopen("test.txt", "rt", stdin);
	//freopen("myfile.txt", "w", stdout);

	memset(a, -1, sizeof(a));
	a[0][0] = 1;
	a[0][1] = 2;
	a[0][2] = 3;
	a[1][0] = 4;
	a[1][1] = 5;
	a[1][2] = 6;
	a[2][0] = 7;
	a[2][1] = 8;
	a[2][2] = 9;
	a[3][1] = 0;
	nub = 0;
	calc(0, 0);
	sort(v.begin(), v.end());
	//for (int i = 0; i < v.size(); i++)
	//cout << v[i] << endl;
	int t, n;
	cin >> t;
	while (t--){
		cin >> n;
		int x = lower_bound(v.begin(), v.end(), n) - v.begin();

		if (x == v.size())
			x--;
		int res = v[x] - n;
		if (x - 1 >= 0 && n - v[x - 1] < res)
			x--;

		//cout << n<< " " <<v[x] << endl;
		cout << v[x] << endl;
	}
	//cout << "g " << endl;
	return 0;
}