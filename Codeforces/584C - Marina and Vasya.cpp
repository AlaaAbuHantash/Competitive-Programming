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
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair
#define pi 2 * acos(0);
#define eps 1e-6

using namespace std;

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int vis[100005];
int  main()
{
	//freopen("test.txt" , "rt" , stdin);
	//freopen ("myfile.txt","w",stdout);
	string a, b;
	int n, k;
	string s = "";
	int g = 0;
	cin >> n >> k >> a >> b;
	for (int i = 0; i < n; i++){
		if (a[i] == b[i])
			vis[i] = 1;
		else
			g++;
	}
	int xx = g / 2;


	bool f = 0;

	if (g - xx > k)
		puts("-1");
	else {
		int z = 0;
		if (g > k){
			for (int i = 1; i <= xx; i++){
				if (g - i <= k){
					z = k - g + i;
					xx = i;
					break;
				}
			}
		}
		else
			z = k - g,xx=0;
		xx = xx * 2;
		for (int i = 0; i < n; i++){
			if (vis[i] && z){
				for (char j = 'a'; j <= 'z'; j++){
					if (j != a[i]){
						s += char(j);
						break;
					}
				}
				z--;
			}
			else if (!vis[i]) {
				if (xx){
					if (f)
						s += char(a[i]);
					else
						s += char(b[i]);
					f = !f;
					xx--;
				}
				else {
					for (char j = 'a'; j <= 'z'; j++){
						if (j != a[i] && j != b[i]){
							s += char(j);
							break;
						}
					}
				}
			}
			else
				s += char(a[i]);
		}
		cout << s << endl;
	}

	return 0;
}