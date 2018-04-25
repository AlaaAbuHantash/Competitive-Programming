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
#include <math.h>
#include<cstdio>
#include<deque>

#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair

using namespace std;
int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ;
int main()
{
	//freopen("test.in" , "rt" , stdin);
	int t , n  ,x , len; 
	string s , temp  , p;
	cin >>t ; 
	while(t-- ) 
	{
		cin >> s ; 
		p="";
		temp="";
		for ( int i = 0 ; i < sz(s) ; i++) 
		{
			p=p+s[i];
			len = i+1;
			n = sz(s) / len ; 
			for ( int j = 0 ; j < n ; j++) 
				temp = temp + p ;

			if ( temp == s ) 
			{
				break;
			}
			temp="";
		}
		cout << sz(p) <<endl;
		if ( t ) 
			cout <<endl;
	}
	return 0;
}


