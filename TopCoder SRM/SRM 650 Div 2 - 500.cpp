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
/*YOU got a DREAM, YOU gotta protect it. */
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dp[111][111][3];
class TaroFillingAStringDiv2 {

public:
	string s;
	int getNumber(string S) {
		s = S;
		memset(dp,-1 , sizeof(dp));
		int res = 1e9;
		if (s[0] == 'A')
			res = calc(1,1, 0);
		else if (s[0] == 'B')
			res = calc(1,1, 1);
		else {
			res = min(res, calc(1,1, 0));
			res = min(res, calc(1,1, 1));
		}
		cout << res << endl;
		return res;
	}
	int calc(int ind,int cc ,  int x) {
		if (ind == s.length())
			return 0;
		int rr = 1e9;
		int z = 0 ;
		if ( dp[ind][cc][x]!= -1 )
			return dp[ind][cc][x];
		if (x == 0) {
				z = 1 ;
			if (s[ind] == '?') {
				rr = min(rr, calc(ind + 1,1, 1));
				rr = min(rr, calc(ind + 1,cc+1, 0)+z);
			} else if (s[ind] == 'A')
				rr = min(rr, calc(ind + 1,cc+1, 0) + z);
			else
				rr = min(rr, calc(ind + 1,1, 1));

		} else if (x == 1) {
				z = 1 ;
			if (s[ind] == '?') {
				rr = min(rr, calc(ind + 1,cc+1, 1)+z);
				rr = min(rr, calc(ind + 1,1, 0));
			} else if (s[ind] == 'A')
				rr = min(rr, calc(ind + 1,1, 0));
			else
				rr = min(rr, calc(ind + 1,cc+1, 1) + z);

		}
		return dp[ind][cc][x] = rr;
	}
};
int main() {
	//freopen("input", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);
	TaroFillingAStringDiv2  A  ;
	A.getNumber("AAABBBAA");
	return 0;
}


