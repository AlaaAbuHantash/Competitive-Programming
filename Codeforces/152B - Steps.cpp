#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility> 
#include <stack>
#include <cstring> 
using namespace std;
int main()
{
	long long int n , m , x , y  , nub  ;
	int i ; 
	cin >> n >> m ; 
	cin >> x >> y ; 
	cin >> nub ; 
	vector<long long int> a( nub )  ; 
	vector<long long int> b( nub )  ; 

	for ( i = 0 ; i < nub ; i ++) 
		cin >> a[i]  >> b[i] ; 

	long long int f , e , mid ; 
	long long int l ,step = 0 ;
	for ( i = 0 ; i < nub ; i ++ ) 
	{

    f = 0; 
	e = 1000000000;
	long long int xn , yn ; 
	while ( f < e ) 
	{
		mid = ( f + e +1 ) / 2  ;
		xn = x + a[i] * mid ; 
		yn = y + b[i] * mid ; 
		//cout << xn << " " << yn << endl;
		if ( xn <= n  && yn <= m && xn >=1  && yn >=1  ) 
			f = mid  ; 
		else 
			e = mid - 1  ; 
	}

	step+= f; 
		x+=a[i] * f; 
		y+= b[i] * f; 
    }

	cout << step << endl;
	return 0;
}