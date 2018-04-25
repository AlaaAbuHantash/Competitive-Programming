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
#define mp make_pair
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int main() {

//freopen("input.in" , "rt" , stdin);
//freopen ("myfile.txt","w",stdout);
	queue<long long> q;

	int n;
	long long x;
	while (scanf("%d", &n) > 0) {
		if (!n)
			return 0;
		long long res = 0;
		queue<long long> a, b;
		for (int i = 0; i < n; ++i) {
			scanf("%lld", &x);
			if (x < 0) {
				x*=-1;
				while (b.size() && x != 0) {
					long long y = min(b.front(), x);
					x -= y;
					b.front() -= y;
					res += y * b.size();
					if (b.front() == 0)
						b.pop();
				}
				if (b.size())
					b.push(0);
				if (a.size() || x)
					a.push(x);
			} else {

				while (a.size() && x != 0) {
					long long  y = min(a.front(), x);
					x -= y;
					a.front() -= y;
					res += y * a.size();
					if (a.front() == 0)
						a.pop();
				}
				if (a.size())
					a.push(0);
				if (b.size() || x)
					b.push(x);
			}

		}
		printf("%lld\n", res);
	}

	return 0;
}


