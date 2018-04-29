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
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	string s ; 
	while (cin >> s ) 
	{
		if ( s == "#" ) 
			break;
		if ( next_permutation(s.begin() , s.end() ) ) 
			cout << s << endl;
		else 
			cout << "No Successor" <<endl;
	}

	return 0 ;
}

