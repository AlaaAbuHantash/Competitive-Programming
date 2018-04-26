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
using namespace std;

int main() {
	double a, b,g; 
	char ch; 
	cin >> a >> ch >> b;
	if (a >= 12)
		a -= 12;
	printf("%.6lf %.6lf\n", ((g = a * 30 + b / 60.0*360.0 / 12.0) == 360) ? 0 : g, b / 60.0*360.0);

	return 0;
}