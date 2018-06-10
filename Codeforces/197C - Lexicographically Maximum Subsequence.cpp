#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
int main() {
	//freopen("input", "rt", stdin);

	string s, tmp = "";
	int lst = 0;
	cin >> s;
	for (int i = 'z'; i >= 'a'; i--) {
		for (int j = lst; j < s.length(); j++) {
			if (s[j] == i) {
				lst = j;
				tmp += s[j];
			}
		}
	}
	cout << tmp << endl;
	return 0;
}

