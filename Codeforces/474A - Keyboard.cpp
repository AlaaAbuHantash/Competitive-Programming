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
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	string a , b ; 
	cin >> a >>b;
	map<char , char > m ;
	if ( a == "R") {
		m['w']='q';
		m['e']='w';
		m['r']='e';
		m['t']='r';
		m['y']='t';
		m['u']='y';
		m['i']='u';
		m['o']='i';
		m['p']='o';
		m['[']='p';
		m[']']='[';

		m['s']='a';
		m['d']='s';
		m['f']='d';
		m['g']='f';
		m['h']='g';
		m['j']='h';
		m['k']='j';
		m['l']='k';
		m[';']='l';
		m['\'']=';';


		m['x']='z';
		m['c']='x';
		m['v']='c';
		m['b']='v';
		m['n']='b';
		m['m']='n';
		m[',']='m';
		m['.']=',';
		m['/']='.';

		rep(i,sz(b)) 
			cout << m[b[i]] ; 
		cout << endl;
	}
	else {
		m['q']='w';
		m['w']='e';
		m['e']='r';
		m['r']='t';
		m['t']='y';
		m['y']='u';
		m['u']='i';
		m['i']='o';
		m['o']='p';
		m['p']='[';
		m['[']=']';

		m['a']='s';
		m['s']='d';
		m['d']='f';
		m['f']='g';
		m['g']='h';
		m['h']='j';
		m['j']='k';
		m['k']='l';
		m['l']=';';
		m[';']='\'';

		m['z']='x';
		m['x']='c';
		m['c']='v';
		m['v']='b';
		m['b']='n';
		m['n']='m';
		m['m']=',';
		m[',']='.';
		m['.']='/';

		rep(i,sz(b)) 
			cout << m[b[i]] ; 
		cout << endl;
	}
	return 0 ;
}
