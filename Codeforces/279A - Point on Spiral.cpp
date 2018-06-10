#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
int main() {
	int x, y, c = 0, xx = 0, yy = 0, r = 1, xu=0 ,yu=0;
	cin >> x >> y;
	if (x != 0 || y != 0)
		while (1) {
		//cout << xx << " " << yy << " " <<  xu <<  " " << yu << endl;
			if (c % 4 == 0) {
				xx++;
				if (yu == y && x<= xx && x >=xu )
					break;
			} else if (c % 4 == 1) {
				yy++;
				if (xx == x && y>= yu && y <= yy )
					break;
			} else if (c % 4 == 2) {
				xu = xx * -1;
				if (yy == y && x<= xx && x >=xu )
						break;
			} else {
				yu=  yy * -1;
				if (xu == x && y>= yu && y <= yy  )
					break;
			}
			c++;
		}

	cout << c << endl;
	return 0;
}

