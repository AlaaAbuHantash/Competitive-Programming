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

int main() {
	//freopen("input.in" , "rt" , stdin);
	//freopen ("myfile.txt","w",stdout);
	int n, a, r;
	while (scanf("%d", &n) > 0) {

		if (n < 0)
			return 0;
		for (int i = 44721; i >= 1; --i) {
			r = i;

			//cout << n * 2 << " " << r * r << " " << 2 * r << endl;
			if (((2 * n) + r - r * r) % (2 * r) == 0
					&& ((2 * n) + r - r * r) /(2 * r) > 0) {

				a = ((2 * n) + r - r * r) / (2 * r);
				//cout << a << endl;
				break;
			}

		}
		printf("%d = %d + ... + %d\n", n, a, a + r - 1);
	}
	return 0;
}


