#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip> 
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

int  main()
{
	//freopen("test.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n;
	string s, beg;
	cin >> n >> s;
	beg = "alaa";
	for (int i = 0; i < s.length(); i++){
		for (int j = '0'; j <= '9'; j++){
			string tmp = s;
			tmp[i] = j;
			
			if (tmp >= "1000" && tmp <= "2011"){
				if (beg == "alaa")
					beg = tmp;
				beg = min(tmp, beg);
	
			}
		}
	}
	vector<string > v; 
	bool f = 1;
	if (beg >= "1000" && beg <= "2011"&& beg != "alaa"){
		v.push_back(beg);
		
	}
	else
		f = 0;
	
	for (int i = 1; i < n&&f; i++){
		cin >> s;
		beg = "alaa";
		for (int k = 0; k < 4&&f; k++)
			for (int j = '0'; j <= '9'; j++){
				string tmp = s;
				tmp[k] = j;

				if (tmp >= "1000" && tmp <= "2011" && v[i - 1] <= tmp){
					if (beg == "alaa")
						beg = tmp;
					beg = min(tmp, beg);
				}
			}
	
		if (v[i - 1] <= beg && beg >= "1000" && beg <= "2011" && beg != "alaa")
			v.push_back(beg);
		else
			f = 0;

	}
	if (!f)
		puts("No solution");
	else
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << endl;
	return 0;
}