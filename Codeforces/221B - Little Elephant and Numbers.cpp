#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int a[10] ;
int main() {
	//freopen("input", "rt", stdin);
	int n;
	vector<int> v;
	cin >> n;
	int x = n;
	while (x != 0) {
		a[x % 10] = 1;
		x = x / 10;
	}
	int res = 0;
	for (int i = 1; i <=  sqrt((double )n); i++){
		if (n % i == 0) {
			x = i;
			while (x != 0) {
				if (a[x % 10]) {
					res++;
					break;
				}
				x = x / 10;
			}


			x = n / i;
			if (i !=  sqrt((double )n) )
			while (x != 0) {
				if (a[x % 10]) {
					res++;
					break;
				}
				x = x / 10;
			}
		}
	}
	cout << res << endl;
	return 0;
}

