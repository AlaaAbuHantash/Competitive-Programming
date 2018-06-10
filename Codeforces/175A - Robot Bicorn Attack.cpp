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
string s , s1 ,s2 ,s3 ;
long long fSum() 
{
	long long  c1 = 0 , c2 = 0 , c3 =0  , x , re; 
	if (( s1[0] == '0' && s1.length() != 1  )  ||  s1.length() > 18 ) 
		return -1 ; 
	if (( s2[0] == '0' && s2.length() != 1 )  ||  s2.length() > 18 ) 
		return -1 ; 
	if (( s3[0] == '0' && s3.length() != 1 )  ||  s3.length() > 18 ) 
		return -1 ; 

	for( int i = 0 ; i < s1.length() ; ++i) 
	{
		if ( i != 0 ) 
			c1 = c1 * 10 ;

		x = s1[i] - '0' ; 
		c1 = c1 + x ; 
	}

	if ( c1 > 1000000)
		return -1;
   for( int i = 0 ; i < s2.length() ; ++i) 
	{
		if ( i != 0 ) 
			c2 = c2 * 10 ;

		x = s2[i] - '0' ; 
		c2 = c2 + x ; 
	}
   if ( c2 > 1000000 ) 
	   return -1;
	for( int i = 0 ; i < s3.length() ; ++i) 
	{
		if ( i != 0 ) 
			c3 = c3 * 10 ;

		x = s3[i] - '0' ; 
		c3 = c3 + x ; 
	}

	re = c1 + c2 + c3;
	if ( c3 > 1000000 )
		return -1 ; 
	
	return re;
}
int maxPoints()
{

	int len = s.length() ;
	long long x; 
	x = -1 ;
	for (int i = 1 ; i  <= len - 2 ; i++ ) 
	{
		s1 = s.substr( 0 , i ) ; 
		for ( int j = 1 ; j < len - i ; j++) 
		{
			s2 = s.substr(i,j) ; 
			s3 = s.substr(j+i) ; 
		//	cout << s1 << " " << s2 << " " << s3 << " " << fSum () << endl;
			x = max ( x , fSum() );
		}
	}

	return x ; 
}
int main()
{
	

	//freopen("test.in" , "rt" , stdin);

	cin >> s ;
	cout << maxPoints() << endl;


	return 0;
}
