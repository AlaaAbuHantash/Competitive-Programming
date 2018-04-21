#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	//freopen("b.txt","rt",stdin);
	double a, b;
	while (cin >> a >> b) {
		double c = 360.0 / b;
		c=c/2.0;
		c = sin(c*acos(-1.0)/180.0);
		c=c*a;
		double w = sqrt((a * a )- (c * c));
		double cc = b * c * w;

		printf("%.3lf\n",cc);
	}
	return 0;
}
