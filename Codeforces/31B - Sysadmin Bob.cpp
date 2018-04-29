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
*   You got a dream, you gotta protect it.
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
int dy[] = {0 ,  0 , 2 ,-2 , 2 , 2 , -2 , -2 } ;
int dx[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ;
int geti(){
	int y = 0, s = 1;
	char c = getchar();
	while ( !isdigit(c) && c!='-' ) c = getchar();
	if ( c == '-' ) s = -1 , c = getchar();
	while ( isdigit(c) ) y = y * 10 + ( c - '0' ) , c = getchar();
	return s * y;
}

int  main()
{   
	//freopen("test.in" , "rt" , stdin);
	string s ,temp,res; 
	cin>>s ; 
	bool f = false;
	int x = s.find('@');
	if ( x ==0|| x == -1 ) f=true;
	else {
		res=s.substr(0,x);
		for(int i=x+1;i<sz(s);i++) {
			if (s[i] == '@'&&sz(temp)<2){
				f=true;break;
			}
			else if (s[i]=='@' ) {
				string t = temp.substr(0,1);
				string t2 = temp.substr(1);
				res+= "@" +t+","+t2;
				temp="";
			}
			else 
				temp+=s[i];
		}
	}
	if (temp.empty() ) f=true; 
	else 
		res+="@"+temp;
	if (f)printf("No solution\n");
	else 
		cout <<res<<endl;
	return 0 ;	
}