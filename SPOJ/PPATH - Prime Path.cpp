#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
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
using namespace std;
int pr[1000000];
map<string, bool > m;
map<string, bool > vis;
void prime(){
	memset(pr, 1, sizeof(pr));
	pr[0] = pr[1] = 0; 
	for (int i = 2; i <= 10000; i++){
		if (pr[i]){
			for (int j = i + i; j < 10000; j += i)
				pr[j] = 0;
			if (i >= 1000 && i <= 9999){
				int tmp = i; 
				string tt = "";
				while (tmp){
					tt = char(tmp % 10 + '0')+tt;
					tmp /= 10;
				}
				m[tt] = 1;
		
			}
		}
	}
}
int main() {
	prime();
	//return 0;
	int t; 
	cin >> t; 
	while (t--){
		string a, b;
		cin >> a >> b; 
		queue<string > q; 
		q.push(a);
		vis.clear();
		int res = 0, f = 0;
		while (!q.empty()){
			int sz = q.size();

			while (sz--){
				string fr = q.front(); 
				q.pop();
				if (fr == b){
					f = 1;
					break;
				}
				vis[fr] = 1;
				for (int i = 0; i < 4; i++){
					char c = '0';
					if (i == 0)
						c = '1';
					for (int j = c; j <= '9'; j++){
						string tmp = fr; 
						tmp[i] = j; 
						if (!vis[tmp] && m[tmp] == 1){
							q.push(tmp);
							vis[tmp] = 1;
						}
					
					}
				}
			}
			if (f)
				break;
			res++;
			
		}
		cout << res << endl;
	}
	return 0;
}