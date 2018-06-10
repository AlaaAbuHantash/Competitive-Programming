#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
int main() {
	//freopen("input", "rt", stdin);
	int n, m, x, y;
	cin >> n >> m;
	bool f = 0;
	if (m % 2)
		f = 1;
	x = m / 2 + 1;
	y = m / 2;
	for (int i = 0; i < n; i++){
		if (f) {
			printf("%d\n", x);
			x++;

			if (x > m && m %2 ) {
				x = m / 2 + 1;
				f = !f ;
			}
			else if ( x > m )
				x = m / 2 + 1;
		} else {
			printf("%d\n", y);
			y--;
			if (y == 0 )
				y = m / 2;
		}
		f= !f ;
	}

	return 0;
}

