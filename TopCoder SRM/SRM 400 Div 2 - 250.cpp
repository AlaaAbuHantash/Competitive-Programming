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
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
class GrabbingTaxi {
public:

	int minTime(vector<int> tXs, vector<int> tYs, int gX, int gY, int walkTime,
			int taxiTime) {
		int res = (abs(gX) + abs(gY)) * walkTime;
		vector<pair<int, int> > p;

		for (int i = 0; i < tXs.size(); i++) {
			for (int j = 0; j < tYs.size(); j++) {
				int x = ((abs(tXs[i]) + abs(tYs[i])) * walkTime)
						+ (abs(gY - tYs[i]) + abs(gX - tXs[i])) * taxiTime;
				res = min(res, x);
			}
		}

		return res;
	}
};
