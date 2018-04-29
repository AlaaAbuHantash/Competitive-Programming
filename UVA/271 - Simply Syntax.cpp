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
You got a dream, you gotta protect it.
*/ 

#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair

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
string s;
int len,x;
bool f;
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	while(cin>>s) {
		x=0;
		len=sz(s);
		f=true;
		for(int i=len-1; i>=0;i--){
			if(!f)break;
			if(s[i]>='p' && s[i]<='z') 
				x++;
			else if (s[i]=='N') 
				if(x>=1) continue;
				else f=false;
			else if (s[i]=='C' ||s[i]=='D'|| s[i]=='E'||s[i]=='I')
				if(x>=2){x-- ; continue;}
				else f=false;
			else 
				f=false;
		}

		
		if(f&&x<2)printf("YES\n");
		else printf("NO\n");

	}
	return 0 ;
}