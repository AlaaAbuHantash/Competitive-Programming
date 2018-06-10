#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <math.h>
using namespace std;
#define mp make_pair
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int main() {
	int n, c = 0;
	cin >> n;
	for (int j = 1; j < n; j++) {
		int x = j;
		bool f = 1;
		for (int i = 1; i < n && f; i++) {
			int r = x%n -1 ;
			if (i == n - 1 && r != 0) {

				f = 0;
			}
			else if (r == 0 && i != n-1 )
				f = 0;

			x=(x*j)%n;
		}
		if (f) c++;
	}
	printf("%d\n", c);
	return 0;
}

