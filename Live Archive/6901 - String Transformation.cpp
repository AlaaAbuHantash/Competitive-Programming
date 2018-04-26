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
using namespace std;

int main() {

	int t; 
	cin >> t; 
	while (t--){
		string a, b;
		cin >> a >> b;
		int c = 0;
		int len = b.size();
		for (int i = 0 ,j ; i < len; i++){
			for (j = i; j < len; j++)
				if (b[i] == a[j])
					break;
			while (j != i){
				c++;
				swap(a[j], a[j - 1]);
				j--;
			}
		}
		printf("%d\n", c);
	}

	return 0;
}