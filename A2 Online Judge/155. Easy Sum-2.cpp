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

#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair

using namespace std;
vector<int > res ;
void fun () 
{
	int a = 1 ;
	res.push_back(1);
	for ( int i = 1 ; i <= 24 ; i++) {

		a = ((a * 2 ) + 1 ) % 33554431;
		res.push_back(a);
		//cout << a << " " << i << endl;
	}
}

int main()
{
	//freopen("test.in" , "rt" , stdin);
	fun () ; 
	int n , t ,x;
	cin >>t ;
	while ( t-- ) 
	{
		cin>>n;
		x = n % 25 ;
		printf("%d\n", res[x]) ; 
	}
	return 0;
}

----------------------------

#include <iostream>
using namespace std;

long long my_pow(long long x, long long y, long long mod) {
    if (y == 0)
        return 1;
    long long ret = my_pow(x, y / 2, mod);
    ret = (ret * ret) % mod;
    if (y % 2 == 1)
        ret = (ret * x) % mod;
    return ret;
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << my_pow(2, n + 1, 33554431) - 1 << endl;
    }
    return 0;
}

