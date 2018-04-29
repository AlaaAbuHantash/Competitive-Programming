#include<iostream>
#include<string>
#include <stdlib.h>
#include<stdio.h>
using namespace std;
int main() {
	string s;
	int t, x, c = 0;
	cin >> t;
	while (t--) {
		cin >> s;
		if (s[0] >= '0' && s[0] <= '9'){
			x = atoi(s.c_str());
			if (x < 18)c++;
		}
		else if (s == "ABSINTH" || s == "BEER" || s == "BRANDY"
				|| s == "CHAMPAGNE" || s == "GIN" || s == "RUM" || s == "SAKE"
				|| s == "TEQUILA" || s == "VODKA" || s == "WHISKEY"
				|| s == "WINE") c++;

	}
	printf("%d\n",c);
	return 0;
}

