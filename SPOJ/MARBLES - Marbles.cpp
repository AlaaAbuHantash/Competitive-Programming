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
#include <cmath>
#include <stdio.h>
#include <string.h>

#define mp make_pair
#define oo ((int) 1e9) 
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=1;i<=(int)(m);i++)
using namespace std;
int main()
{
	//freopen("test.in" , "rt" , stdin);
	int t ;
	unsigned long long int a , b , r , c ; 
	cin >> t ; 
	rep(i,t) {
		r=1;
		cin >> a >> b ; 
		a--;
		b--;
		c=min(b , a-b ) ;
		rep(i, c ) {
		     r = (r*(a - i + 1))/i ; 
		}
		cout << r << endl;
	}
	return 0 ;
}