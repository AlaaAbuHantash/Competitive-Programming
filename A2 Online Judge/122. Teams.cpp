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
#include <stdio.h>
using namespace std;
int GCD( int a , int b)
{
        if(a%b==0) return b;
        return GCD(b,a%b);

}
int main()
{
	
	//freopen("test.in" , "rt" , stdin);
	int t  , a ,b  , r , m  ; 
	cin >> t ; 
	while ( t-- ) 
	{
		cin >> a >> b ;
		r = GCD(a,b);
		 m = (a/r) * (b/r) ; 
		cout << r << " " << m << endl;

	}

	return 0;
}