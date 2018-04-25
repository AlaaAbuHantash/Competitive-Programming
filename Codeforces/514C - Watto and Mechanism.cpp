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
#include<math.h>
#include<time.h>
/*YOU got a DREAM, YOU gotta protect it. */
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
vector<vector<int> > v;
bool res;
vector<int> cnt;
void add(string s) {
	int x = 0;
	for (int i = 0; i < s.length(); i++) {
		if (v[x][s[i] - 'a'] == -1) {
			v.push_back(vector<int>(3, -1));
			v[x][s[i] - 'a'] = v.size() - 1;
			cnt.push_back(0);
		}
		x = v[x][s[i] - 'a'];
	}
	cnt[x]++;
}
bool f ;
string s ;
int calc(int c, int ind, int st) {
	//cout << s << " " << c << " " << ind <<  " " << st << endl;
	int r = 0;
	if ( f )
		return 1 ;

	if (ind == s.length() && cnt[st] && c ){
		f = 1 ;
		return 1;
	}
	if (ind >= s.length())
		return 0;
	if(c)
	for ( ; ind < s.length()-2 ; ind++ )
		if (v[st][s[ind]-'a'] != -1 )
			st = v[st][s[ind]-'a'];
		else
			break;

	for (int j = 0; j < 3; j++) {
		if (j == s[ind] - 'a' && v[st][j] != -1) {
			r = max(r, calc( c, ind + 1, v[st][j]));
		}
		if (v[st][j] != -1 && c == 0 && j != s[ind] - 'a' ) {
			 r = max(r, calc( 1, ind + 1, v[st][j]));
		}

	}
	return r ;
}
int main() {

	//freopen("input", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);
	int a, b;
	cin >> a >> b;
	cnt.push_back(0);
	v.push_back(vector<int>(3, -1));
	for (int i = 0; i < a; i++) {
		cin >> s;
		add(s);
	}
	for (int i = 0; i < b; i++) {
		cin >> s;
		f=0;
		if (calc( 0, 0, 0))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}

