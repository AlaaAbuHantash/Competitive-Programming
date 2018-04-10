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

int main() {
	//freopen("A.txt", "rt", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		long long n, nn, d, dd, f, ff;
		scanf("%lld%lld%lld%lld%lld%lld", &n, &f, &d, &nn, &ff, &dd);
		if (f > ff) {
			swap(f, ff), swap(d, dd), swap(n, nn);
		}

		ff -= f;
		f = (n - 1) * d;
		long long lst = min((nn - 1) * dd + ff, f);
	
		int res = 0;
		pair<long long , long long > p1 = mp(-1, -1);
		for (long long i = ff, cnt = 0; cnt < nn; i += dd, cnt++) {
			
			if (i > f)
				break;
			if (i == 0 || i % d == 0) {

				if (p1.first == -1)
					p1.first = i;
				else if (p1.second == -1){
					p1.second = i;
					break;
				}
				else {
					dd = p1.second - p1.first;
					break;
				}
				res++;
			}

		}
		//cout << lst << endl;
		if (p1.first != -1 && p1.second != -1) {
			dd = p1.second - p1.first;
			//cout << lst - p1.first<< " " << dd << endl;
			res = (lst - p1.first) / dd;
			res++;
		}
		printf("%d\n", res);
	}
	return 0;
}

