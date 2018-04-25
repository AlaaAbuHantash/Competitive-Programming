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
     
    string a, b, c , s ;
    vector<int> v;
    void fun() {
    	v.clear();
    	int m = s.length();
    	v.resize(m + 2);
    	int i = 0, j = -1;
    	v[0] = -1;
    	while (i < m) {
    		while (j >= 0 && s[i] != c[j])
    			j = v[j];
    		i++;
    		j++;
    		v[i] = j;
    	}
    	v[0] = 0;
    }
    int lena, lenb,lenc;
    int dp[111][111][111];
    int calc(int x, int y, int ind){
    	//cout << x << " " << y << " " << ind << endl;
    	if (x == lena && y == lenb && ind < lenc )
    		return 0;
     
    	if (x > lena || y > lenb || ind >= lenc)
    		return -1000000;
    	if (dp[x][y][ind] != -1)
    		return dp[x][y][ind];
    	int r = 0 , r2 = 0; 
    	if (a[x] == b[y] && a[x] == c[ind])
    		r = calc(x + 1, y + 1 ,ind+1) + 1;
    	if (a[x] == b[y] && a[x] != c[ind]){
    		if (c[v[ind]] == a[x])
    			r2 = calc(x + 1, y + 1, v[ind]+1) + 1;
    		else 
    			r2 = calc(x + 1, y + 1, 0) + 1;
     
    	}
     
    	return dp[x][y][ind] = max ( max(r,r2) , max(calc(x + 1, y ,ind), calc(x, y + 1 , ind)));
    }
     
     
    void build(int x, int y , int ind){
    	if (x == lena && y == lenb){
    		puts("");
    		return;
    	}
     
    	int r = 0 , r2 = 0, rr = calc(x + 1, y, ind),rrr= calc(x, y + 1, ind);
    	if (a[x] == b[y] && a[x] == c[ind])
    		r = calc(x + 1, y + 1, ind + 1) + 1;
    	else if (a[x] == b[y] && a[x] != c[ind]){
    		if (c[v[ind]] == a[x])
    			r2 = calc(x + 1, y + 1, v[ind] + 1) + 1;
    		else
    			r2 = calc(x + 1, y + 1, 0) + 1;
    	}
     
    	int z = max(max(r, r2), max(rr, rrr));
     
    	if (a[x] == b[y] && a[x] == c[ind] && z == r){
    		cout << a[x];
     
    		build(x + 1, y + 1,ind+1) ;
    	}
    	else if (a[x] == b[y] && a[x] != c[ind] && z == r2){
    		cout << a[x];
    		if (c[v[ind]] == a[x])
    			build(x + 1, y + 1, v[ind] + 1);
    		else
    			build(x + 1, y + 1, 0) ;
    	}
    	else if (z == rr)
    		build(x + 1, y, ind);
    	else
    		build(x, y + 1, ind);
    }
     
    int main() {
    	//freopen("A.txt", "rt", stdin);
    	cin >> a >> b >> c;
    	s = c;
    	fun();
    	memset(dp, -1, sizeof(dp));
    	lena = a.length();
    	lenb = b.length();
    	lenc = c.length();
     
    	//for (int i = 0; i < lenc+1; i++)
    	//	cout << v[i] << endl;
    	int res = calc(0, 0 ,0);
    	if (res)
    		build(0, 0, 0);
    	else 
    		puts("0");
     
    	return 0;
    }
     
     