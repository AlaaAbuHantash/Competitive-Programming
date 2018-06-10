#include<iostream>
#include<string>
#include <stdlib.h>
#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;
#define mp make_pair
int main() {
	int a, b, c;
	cin >> a >>b>> c;
	c = c * 2;
	if (a >= c)
		a = 1;
	else
		a = a/c;
	if (b >= c)
		b = 1;
	else
		b = b/c;

	if ((a * b) % 2 == 1)
		puts("First");
	else
		puts("Second");
	return 0;
}

