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
int t ; 
string s ; 

int toint(string s) 
{
	int x , a = 0 , r = 0 ; 
	rep(i,sz(s) ) 
	{
		if ( i ) 
			r = r * 10 ;
		x = s[i] - 48 ; 
		r =r +x; 

	}
	return r ; 
}
void fun1 (string s ) 
{
	int x = s.find('C' ) ;
	string s1 = s.substr(1, x-1 )  , r; 
	string s2= s.substr(x+1) ; 
	int n=  toint(s2 ) ; 




	while (n != 0 )
	{
		x = n %26 ;
		if ( x == 0 ) {
			n--;
			x = 26 ;
		}
		r = char ( x +'A'- 1 ) + r  ;
		n = n / 26 ;
	}
	
	cout << r  << s1 << endl;
}

void fun2 ( string s ) 
{
	int x = 0 , r = 0 ;
	string s1 = "" , c = ""  ;
	rep(i , sz(s) ) 
		if ( isdigit(s[i] ) ) 
			c+=s[i];
		else 
			s1+=s[i] ; 

	rep(i,sz(s1)) 
	{
		if ( i ) 
			r = (r + x) * 26;
		
		x =  s1[i] - 64 ; 
	}

	r = r + x ; 
	
	cout << "R" << c << "C" << r <<endl;
}

int main()
{
	//freopen("test.in" , "rt" , stdin);
	
	cin>> t ; 
	while ( t-- ) 
	{
		cin >> s ; 
		int f = s.find('C' , 2 ) ; 
		//cout << f <<endl;
		if ( s[0] == 'R' && isdigit (s[1] ) && f < sz(s) && f > 0) 
			fun1(s) ; 
		else
			fun2(s) ; 
	}

	return 0 ;
}