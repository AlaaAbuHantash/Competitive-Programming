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
using namespace std;
int main()
{
	
//  freopen("test.in" , "rt" , stdin);

	int a , b  , a1 , b1 , x  = 0, m = 0  ,c = 0 , r , count=0 , f = 0;
	cin >> a >> b ; 
	a1 = a ; b1 = b ; 
	while ( a1 != 0 ) 
	{
		x = a1 % 10 ; 
		a1 = a1 / 10 ; 
		m = max ( m , x ) ;
	}
	while ( b1 != 0 ) 
	{
		x = b1 % 10 ; 
		b1 = b1 / 10 ; 
		m = max ( m , x ) ;
	}
	m++;
	
	r = 0;
	c = 0 ;
	while ( a || b || c ) // bjma3 bel nesbh ll base m 
	{
		if ( a) 
		r = r + a % 10 , a = a / 10 ;
		if ( b ) 
		r = r + b % 10  , b = b / 10 ; 

		 
		
		c = r / m ;  // betamoh znat shtoo astalas ominah .. 
		
		r = c; 
		f++;
	}
	cout << f << endl;
	return 0;
}
