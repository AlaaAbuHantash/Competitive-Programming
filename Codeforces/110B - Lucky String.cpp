#include <iostream>
#include<string>
#include<map>
#include<algorithm>
#include<sstream>
#include<vector>
#include<math.h>
#include<stdio.h>
using namespace std;
int a[50005];
int p[6];
int main() {
	//freopen("input", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);
	string s = "abcd", res = "";
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		res += s[i % 4];
	cout << res << endl;
	return 0;
}

