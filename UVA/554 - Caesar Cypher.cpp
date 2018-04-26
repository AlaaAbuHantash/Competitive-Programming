#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <stack>
#include <cstring>
#include <math.h>
#include<cstdio>
#include<deque>
#include<sstream>
#include <stdio.h>
#define mp make_pair
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
map<string, int> m;
string s;
int main() {

	string a = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//freopen("A.txt" , "rt" , stdin);
	//freopen ("myfile.txt","w",stdout);
	while (cin >> s && s != "#") {
		m[s]++;
	}

	getline(cin, s);
	getline(cin, s);

	int c = 0, res = 0;
	string rres = "";
	for (int i = 0; i < 27; i++) {
		string tmp = s;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == ' ')
				s[j] = 'A' - 1;
			int x = s[j] - 'A' - i;
			if (x < 0)
				x += 27;
			tmp[j] = a[x];
		}
		string r = "";
		for (int j = 0; j < tmp.size(); j++) {
			if (tmp[j] == ' ') {
				if (r.size() && m[r] == 1)
					c++;
				r = "";
			} else
				r += tmp[j];
		}

		if (c > res) {
			res = c;
			rres = tmp;
		}
	}
	stringstream A(rres);
	vector<string > v ;
	while(A>>s)
		v.push_back(s);
	int len = 0 ;
	for ( int i = 0 ; i <v.size() ; i++){
		int cc = 0 ;
		if ( len != 0 )
			cc = 1;
		if ( len +v[i].length() + cc  <= 60){
			if ( len != 0 )
				cout << " "  ;
			cout << v[i] ;
			len+=v[i].length()+cc;
		}
		else {
			if(i!=0)
				puts("");
			len = 0 ;
			len+=v[i].length();
			cout << v[i] ;
		}
	}
	puts("");
	return 0;
}


