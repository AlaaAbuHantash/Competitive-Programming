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

#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
 
#define oo ((int) 1e9)
#define mp make_pair

using namespace std;
int main()
{
	//freopen("test.in" , "rt" , stdin);
	int n ; 
	string a[] = {"00", "01" , "81"} ;
	string b[] = {"0000" , "0001" , "2025" , "3025" , "9801" } ; 
	string c[] = {"000000" ,"000001" , "088209" , "494209" , "998001"  } ; 
	string d[] = {"00000000" ,"00000001" , "04941729","07441984","24502500","25502500" ,"52881984" ,"60481729","99980001"  } ; 

	while ( cin >> n ) 
		if ( n == 2 )
			rep (i , 3 ) 
			  cout << a[i]<<endl;
		else if ( n == 4 ) 
			rep (i , 5) 
			  cout << b[i]<<endl;
		else if ( n == 6 ) 
			rep ( i , 5 ) 
			cout << c[i]<<endl; 
		else if ( n == 8 ) 
			rep ( i , 9 ) 
			cout << d[i]<<endl;

	return 0;
}
