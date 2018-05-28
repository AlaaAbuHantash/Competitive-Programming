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

	string s1 , s2 ;
	cin >> s1 >> s2 ; 
	int n4=0 , n7=0 , x4=0 , x7 = 0 ;
	for ( int i = 0 ;i < s1.length() ; i++) 
	{
		if ( s1[i] == s2[i])
			continue;
		if ( s1[i] == '4' ) 
			n4++;
		if ( s1[i] == '7')
			n7++;
		if (s2[i] == '7' ) 
			x7++;
		if ( s2[i]=='4')
			x4++;
	}
	int z =0 , z1=0 ;
	//cout << n4 << " " << n7 << endl;
	if ( n4 < n7 ) 
		{
			z = n4 ; 
			z1 = n7;
	    }
	else// if ( n7 < n4 ) 
		{
			z = n7 ; 
			z1 = n4;
	 }
	int w =0 , w1=0 ;
	if ( x4 < x7 ) { w = x4; w1 = x7 ;}
	else //if ( x7 < x4 )
	{w = x7; w1 = x4 ;}

	int b = max ( w1 , z1 ) ; 
	int a = min ( w , z ) ;

	//cout << b << " " << a << endl;
	//cout << n4 << n7 << x4 << x7 << endl;

		cout << a + (b-a) <<endl;


	return 0;
}

