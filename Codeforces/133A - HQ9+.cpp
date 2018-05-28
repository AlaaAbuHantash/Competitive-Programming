#include <cstdio>
#include <cstdlib>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

int gcd (int n , int k )
{
	int i ; 

/*if( k == 0 )
   return n ; 
else if( n == 0 )
   return k ; 
*/
for (i = n ; i > 0 ; i--)
		{// cout << i <<endl ;
			if (k%i == 0 && n%i==0 ) 
	    	return i; }


}

int main()
{
	string s ; 
	int i , x= 0 ; 
	cin >> s ; 

	for (i = 0 ; i < s.length() ; i++ )
		if (s[i] == 'H' || s[i] == 'Q'|| s[i] == '9' )
			x = 1 ; 

	if (x)
		cout <<"YES"<< endl; 
	else 
		cout <<"NO"<< endl; 
  return 0;
}
