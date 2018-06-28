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
#include<sstream>

/*
*	You got a dream, you gotta protect it.
*/ 

#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair
#define pi 2 * acos(0);
#define eps 1e-6



using namespace std;

int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ; 

int geti(){
	int y = 0, s = 1;
	char c = getchar();
	while ( !isdigit(c) && c!='-' ) c = getchar();
	if ( c == '-' ) s = -1 , c = getchar();
	while ( isdigit(c) ) y = y * 10 + ( c - '0' ) , c = getchar();
	return s * y;
}

int n ; 
string s ;
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	scanf("%d",&n ) ; 
	cin>>s;

	if ( sz(s) == 8 ) 
		cout <<"vaporeon\n " ;  
	else if ( sz(s) == 6 ) 
		cout <<"espeon\n";
	else {
		if ( s[0] == 'j' || s[1] =='o' || s[3] =='t') 
			cout << "jolteon\n"; 
		else if (s[0] =='f'  || (s[1] =='l' && s[3 ] =='r') || (s[2] =='a' && s[3 ] =='r')) 
			cout <<"flareon\n";
		else if (s[0] =='u' || s[1] =='m' || s[2]=='b')
			cout << "umbreon\n";
		else if (s[0] =='l' || s[1] == 'e' || s[3] =='f' ) 
			cout << "leafeon\n";
		else if (s[0] =='g' || s[3]=='c' || (s[1 ] =='l' && s[2]=='a')  ) 
			cout << "glaceon\n" ; 
		else 
			cout << "sylveon\n";
	}
	return 0 ;
}
