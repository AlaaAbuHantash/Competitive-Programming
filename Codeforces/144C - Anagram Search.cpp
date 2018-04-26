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
#define mp make_pair
#define eps 1e-6
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int aa[33], bb[33];
int main()
{
	//freopen("test.txt", "rt", stdin);
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < b.length(); i++)
		bb[b[i] - 'a']++;
	int c = 0, g = 0, cnt = 0,st=0;
	for (int i = 0; i < a.length(); i++){
		if (a[i] == '?')
			g++;
		else{
			aa[a[i] - 'a']++;
			if (aa[a[i] - 'a'] > bb[a[i] - 'a']){
				while (st <= i){
					if (aa[a[i] - 'a'] <= bb[a[i] - 'a']){
						if (aa[a[i] - 'a'])
							c++;
						break;
					}
					else if (st == i){
						st++;
						break;
					}
					if (a[st] == '?')
						g--;
					else {
						c--;
						aa[a[st] - 'a']--;
					}
					st++;
				}
			}
			else
				c++;

		}
		if (c + g == b.length()){
			cnt++;
			if (a[st] == '?')
				g--;
			else {
				c--;
				aa[a[st] - 'a']--;
			}
			st++;
		}
		if (c + g > b.length()){
			
			if (a[st] == '?')
				g--;
			else {
				c--;
				aa[a[st] - 'a']--;
			}
			st++;
		}
	}
	cout <<  cnt << endl;
	return 0;
}


