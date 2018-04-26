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

int  main()
{
	//freopen("test.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);
	 double a, b, c;
	cin >> a >> b >> c;
	 double sq = b*b-(4*a*c);
	if (sq >= 0 && a != 0){
		 double x = (-b + sqrt(sq)) /( 2 * a);
		 double y = (-b - sqrt(sq)) / (2 * a);
		if (x != y){
			puts("2");
			printf("%.6lf\n%.6lf\n", min(x,y), max(x,y));
		}
		else{
			puts("1");
			printf("%.6lf\n", x);
		}
	}
	else if (a == 0 && b != 0){
		double x = -c / b;
		puts("1");
		printf("%.6lf\n", x);
	}
	else if (c!=0)
		puts("0");
	else
		puts("-1");
	return 0;
}