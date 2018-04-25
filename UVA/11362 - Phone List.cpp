#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
string s;
vector<vector<int> > adj;
void add() {
	int cur = 0;
	for (int i = 0; i < s.length(); i++) {
		if (adj[cur][s[i] - '0'] == -1) {
			adj.push_back(vector<int>(12, -1));
			adj[cur][s[i] - '0'] = adj.size() - 1;
		}
		cur = adj[cur][s[i] - '0'];
	}
}
bool find() {
	int cur = 0 ;
	for ( int i = 0 ; i < s.size() ; i++ ){
		if (adj[cur][s[i] - '0'] == -1 )
			return 0 ;
		cur = adj[cur][s[i] - '0'] ;
	}
	return 1 ;
}

int main() {
	//freopen("input", "rt", stdin);
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		adj.clear();
		adj.push_back(vector<int>(12, -1));
		vector<string> ss;
		for (int i = 0; i < n; i++) {
			cin >> s;
			ss.push_back(s);
		}
		bool f =0 ;
		sort(ss.rbegin(), ss.rend());
		for (int i = 0; i < n; i++) {
			s = ss[i] ;
			if(find())
				f= 1;
			add();
		}
		if (f)
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}

