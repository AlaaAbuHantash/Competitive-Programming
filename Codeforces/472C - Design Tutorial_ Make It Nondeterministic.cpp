#include <iostream>
#include<string>
#include<map>
#include<algorithm>
#include<sstream>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<string.h>
using namespace std;
#define mp make_pair
int main() {
	//freopen("input", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);
	string a, b;
	vector<pair<string, string> > s;
	int t, x;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		if (a < b)
			s.push_back(mp(a, b));
		else
			s.push_back(mp(b, a));
	}
	bool f = 1;
	string tmp;
	cin >> x;
	tmp = s[x - 1].first;

	for (int i = 1; i < t; i++) {
		cin >> x;
		if (s[x - 1].first > tmp)
			tmp = s[x - 1].first;
		else if (s[x - 1].second > tmp)
			tmp = s[x - 1].second;
		else
			f = 0;

	}

	if (f)
		puts("YES");
	else
		puts("NO");

	return 0;
}

