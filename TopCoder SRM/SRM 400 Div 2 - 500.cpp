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
#define eps 1e-9
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
class StrongPrimePower {
public:
	vector<int> baseAndExponent(string n) {
		int len = n.length();
		vector<int> res;
		long long nub = 0;
		for (int i = 0; i < len; i++)
			nub = nub * 10 + (n[i] - '0');

	///	cout << nub << endl;
		bool g = 0;
		for (int i = 2; i <= 100 && !g; i++) {
			long long r = (long long) (pow(nub, 1.0 / i) + eps);

			long long x = r;
			for (int j = 0; j < i - 1; j++) {
				x = (long long) x * (long long) r;
			}
			//cout << x << " " << r << endl;
			if (x == nub) {
				bool f = 1;
				for (long long j = 2; j * j <= r && f; j++)
					if (r % j == 0)
						f = 0;
				if (f) {
					g = 1;
					res.push_back(r);
					res.push_back(i);
				}
			}

		}

		return res;
	}
};
int main() {
	//freopen("test.txt", "rt", stdin);
	StrongPrimePower g;
	g.baseAndExponent("94931877133");
	return 0;
}
