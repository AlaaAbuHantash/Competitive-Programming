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
class RelativePath {
public:
	string makeRelative(string path, string currentDir) {
		vector<string> a, b;
		string tmp = "";
		for (int i = 0; i < path.length(); i++)
			if (path[i] != '/') {
				tmp += path[i];
			} else {
				if (tmp.size())
					a.push_back(tmp);
				tmp = "";
			}
		if (tmp.size())
			a.push_back(tmp);
		tmp = "";
		for (int i = 0; i < currentDir.length(); i++)
			if (currentDir[i] != '/') {
				tmp += currentDir[i];
			} else {
				if (tmp.size())
					b.push_back(tmp);
				tmp = "";
			}
		if (tmp.size())
			b.push_back(tmp);
		int c = 0, cc = 0;
		for (int i = 0; i < a.size() && i < b.size(); i++)
			if (a[i] != b[i]) {
				c = b.size() - i;
				cc = i;
				break;
			}

		//cout << c << endl;
		if (c == 0) {
			tmp = "" ;
			tmp += a[b.size()];
			for ( int i = b.size()+1 ; i < a.size() ; i++)
				tmp+="/" + a[i];
		} else {
			tmp = "";
			for (int i = 0; i < c; i++)
				tmp += "../";

			tmp += a[cc];
			for (int i = cc + 1; i < a.size(); i++)
				tmp += "/" + a[i];
		}
		//cout << tmp << endl;

		return tmp;

	}
};
