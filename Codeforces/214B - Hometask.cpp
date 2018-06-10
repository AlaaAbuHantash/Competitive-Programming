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
using namespace std;

int main()
{


	//freopen("test.in" , "rt" , stdin);
	int n  , sum=0 , x , o = 0  , th , z =0 , o1; 
	string s ; 
	cin >> n ;
	vector<int >a(n);
	int g[2] , t[2] ;
	bool f = false , f2 = false , ou = false , fi = false;;
	for ( int i = 0 ; i < n ; i++) 
	{
		cin >> a[i] ;
		sum = sum + a[i];
		if(a[i] == 0)
		{
		  f=true;
		  fi = true;
		}
	}

	s="";

	sort (a.begin() , a.end() ) ;

	if ( sum%3 == 0  ) 
		f2 = true; 
	else 
		x = sum%3 ;

	//cout << x << endl;
	//cout << sum << endl;
	if (!f2 && f )
	{
		o=0;
		o1= 0 ; 
		for ( int i = 0 ; i < n ; i ++)
		{
			if ( a[i]%3 == 2  && o1 != 2 ) 
			{
				t[o1]= a[i] ; 
				o1++;
				ou = true; 
			}
			else if ( a[i]%3 == 1  && o != 2 ) 
			{
				g[o] = a[i];
				o++;
				ou = true;
			}

			if ( o1 == 2 && o == 2 )
				break;
		}


	if ( ou ) 
	{
		ou = false;
		if ( x == 2  && o1 >= 1 )
		{
			for ( int i = n-1 ; i >=0 ;i--)
				if ( a[i] == t[0]  && !ou ) 
					ou = true;
				else 
					s= s + char ('0' + a[i]) ;
		}
		else if ( x == 2 && o >= 2)
		{
			th = 2 ;
			for ( int i = n-1 ; i >=0 ;i--)
				if ( a[i] == g[0]  && th ) 
					th--;
				else if ( a[i] == g[1] && th ) 
					th--;
				else 
					s= s + char ('0' + a[i]) ;
		}

		else if ( x == 1  && o >= 1 ) 
		{
			th = 1 ;
			for ( int i = n-1 ; i >=0 ;i--)
				if ( a[i] == g[0]  && th ) 
					th-- ;
				else 
					s= s + char ('0' + a[i]) ;
		}
		else if ( x == 1 && o1>=2)
		{
			th = 2 ;
			for ( int i = n-1 ; i >=0 ;i--)
				if ( a[i] == t[0]  && th ) 
					th--;
				else if ( a[i] == t[1] && th ) 
					th--;
				else 
					s= s + char ('0' + a[i]) ;
		}
	}
	
	}
	else if ( f2 && f )
	{
	    for ( int i = n-1 ; i >=0 ;i--)
			  s= s + char ('0' + a[i]) ;
	}


	for ( int i = 0 ; i < s.length() ; i ++ ) 
		if ( s[i] == '0') 
			z++ ;
	
	if ( z == s.length()  && z != 0 ) 
		s = "0";


	if ( s.empty() && fi) 
		s = "0" ;

	if ( s.empty() ) 
		cout << "-1" << endl;
	else 
		cout << s << endl;
	return 0;
}
