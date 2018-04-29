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

#define mp make_pair

using namespace std;

int main()
{
	//freopen("test.in" , "rt" , stdin);
	string S, a , b ;
	int n ; 
	vector<string > s (3);
	for ( int i = 0 ; i < 3 ; i++) 
	{
		cin >>S ;
		a="";
		for ( int j = 0 ; j < S.length() ; j++) 
			if ( S[j] != '-' && S[j] != '_' &&S[j] != ';' ) {
				S[j] = tolower (S[j] );
			  a = a + S[j];
			}
		s[i] = a;
	}

	cin >> n ;
	b = "" ;
	for ( int i = 0 ; i < n ; i++)  {
		cin >> S ; 
		b = "";
		for ( int j= 0 ; j < S.length() ; j++) 
			if ( S[j] != '-' && S[j] != '_' &&S[j] != ';' ){
				S[j] = tolower(S[j]);
				b = b+S[j];
			}

	if ( s[0] + s[1] + s[2] == b || s[0] + s[2] + s[1] == b || s[1] + s[2] + s[0] == b|| s[1] + s[0] + s[2] == b || s[2] + s[1] + s[0] == b  || s[2] + s[0] + s[1] == b )
		cout << "ACC"<<endl;
	else 
		cout << "WA"<<endl;
	}
	return 0 ;
}