#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int main() {
	//freopen("input", "rt", stdin);
	int n, a, b, c=0;
	cin >> n;
	vector<int> v,vv;
	for ( int i = 0 ;i < n ; i ++ ){
		cin >> a ;
		v.push_back(a);
		vv.push_back(a);
	}
	sort(v.begin() , v.end());
	for ( int i = 0 ;i < n ; i ++ ){
		if ( v[i] != vv[i])
			c++;
	}
	if (c>2)
		puts("NO");
	else
		puts("YES");
	return 0;
}

