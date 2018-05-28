#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	int i ; 
	string s ,r; 

	r="";#include <iostream>
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

	string s = "><+-.,[]" , s1;
	cin >> s1 ;
	int r = 0 ;
	for ( int i = 0 ; i < sz(s1) ; i++) 
		r = ( r *16 + 8 + s.find(s1[i]) )% 1000003 ; 


	cout << r << endl;


	return 0;
}
	cin >> s ; 
	for ( i= 0 ; i < s.length() ; i++)
	{
		if ('>' ==s[i])
		r = r + "8";
		else if ('<' ==s[i])
		r = r + "9";
		else if ('+' ==s[i])
		r = r + "1010";
		else if ('-' ==s[i])
		r = r + "1011";
		else if ('.' ==s[i])
		r = r + "1100";
		else if (',' ==s[i])
		r = r + "1101";
		else if ('[' ==s[i])
		r = r + "1110";
		else if (']' ==s[i])
		r = r + "1111";
	}

//	cout << r<<endl;
    long long int sum=0 , a = 0 , z , k;
	for( int i = r.length()-1 ; i != -1 ; i--)
	{
		if (r[i]=='1')
			sum = sum + pow(2.0,a) ; 

		//	cout << sum<<endl;
		a++;

	}

		sum= sum %1000003;


	cout << sum<<endl;
  return 0;
}


