/**			
***** Judge
******* Yourself 
********* Only   
*/
#define _CRT_SECURE_NO_WARNINGS
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
#include<cmath>
using namespace std;
#define mp make_pair
#define eps 1e-6
vector<vector<int> > g;
vector<int> cnt;
string s ; 
int res = 0;
void add() {
	int cur = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (g[cur][s[i] - '0'] == -1) {
			g.push_back(vector<int>(2, -1));
			cnt.push_back(0);
			g[cur][s[i] - '0'] = g.size() - 1;
		}
		cur = g[cur][s[i] - '0'];
		++cnt[cur];
		res = max(cnt[cur] *(i+1) , res);
	}

}
int main() {
	//freopen("a.txt", "rt", stdin);
	//freopen("out.txt", "w", stdout);
	int t , n ; 
	scanf("%d",&n); 
	while(n--){
		scanf("%d",&t);
		res = 0 ;
		cnt.clear();
		g.clear();
		g.push_back(vector<int>(2,-1));
		cnt.push_back(0);
		while(t--){
			cin >> s ; 
			add();
		}
		printf("%d\n",res);
	}

} 
