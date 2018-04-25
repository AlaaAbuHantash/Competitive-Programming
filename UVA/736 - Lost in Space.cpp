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
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

vector<string> v;
string dir[] = { "N", "NE", "E", "SE", "S", "SW", "W", "NW" };
int len,n; 
bool f;
int sx, sy,sind;
string s;
void calc(int x, int y, int ind){
	if (ind == len){
		f = 1;
		printf("(%d,%d) - %s\n", sx+1, sy+1, dir[sind].c_str());
		return  ;
	}

	int nx = dx[sind] + x;
	int ny = dy[sind] + y;
	if (nx < 0 || ny < 0 || nx >= n || ny >= n)
		return;

	if (v[nx][ny] == ' ')calc(nx, ny, ind);
	if (v[nx][ny] == s[ind])calc(nx, ny, ind + 1);

	return; 
}
int  main()
{
	
	//freopen("A.txt", "rt", stdin);
	//freopen ("myfile.txt","w",stdout);
	int t; 
	scanf("%d", &t);
	cin.ignore();
	bool first = 0;
	while (t--){
		if (first)
			puts("");
		first = 1; 
		v.clear();
		scanf("%d", &n);
		cin.ignore();
		for (int i = 0; i < n; i++){
			getline(cin, s);
			v.push_back(s);
		}

		while (getline(cin, s)&&s.length()!=0){
			len = s.length(); 
			cout <<endl<< s << endl;
			f = 0;
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					for (int k = 0; k < 8; ++k)
						if (s[0] == v[i][j])
							sx = i, sy = j, sind = k, calc(i, j, 1);
			if (!f)
				puts("not found");
			
		}
	}
	return 0;
}