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
int n,x,g,z;
string ss,temp;
int a,b,c ,oc,ob,oa ; 
vector < string > aa,bb,cc;
int  main()
{   
	//freopen("test.in" , "rt" , stdin);
	scanf("%d",&n) ; 
	oa=0;ob=0;oc=0;
	for(int i =0;i<n;i++) {
		scanf("%d",&x);
		cin>>ss;
		a=0;b=0;c=0;
		for(int j=0; j<x;j++) {
			cin >> temp;
			temp=temp+"0";
			z=0;g=0;

			if ( temp[0] == temp[1]  && temp[1] == temp[3] && temp[1] == temp[4] && temp[1] == temp[7] && temp[1] == temp[6]) 
				g=1;
			else if ( temp[0] > temp[1]&& temp[1] > temp[3] && temp[3] > temp[4] && temp[4] > temp[6] && temp[6] > temp[7])  
				z=1;
			if ( g) 
				a++;
			else if (z)
				b++;
			else 
				c++;
		}
			if (oa == a ) {
				aa.push_back(ss);
			}
			if (  oa < a ) {
				aa.clear();
				oa=a;
				aa.push_back(ss);
			}	
			if (ob == b){ 
				bb.push_back(ss);
			}
			if ( ob < b){ 
				ob=b;
				bb.clear();
				bb.push_back(ss);
			}
			if (  oc == c  ) {
				cc.push_back(ss);
			}
			if ( oc < c ) {
				oc = c ; 
				cc.clear();
				cc.push_back(ss);
			}
		

	}

	printf("If you want to call a taxi, you should call:");
	for (int i =0 ; i < sz(aa) -1; i++) 
		cout << " " << aa[i] << "," ; 
	cout << " " << aa[sz(aa)-1] << ".\n" ; 

	printf("If you want to order a pizza, you should call:");
	for (int i =0 ; i < sz(bb) -1; i++) 
		cout << " " << bb[i] << "," ; 
	cout << " " << bb[sz(bb)-1] << ".\n" ; 

	printf("If you want to go to a cafe with a wonderful girl, you should call:");
	for (int i =0 ; i < sz(cc) -1; i++) 
		cout << " " << cc[i] << "," ; 
	cout << " " << cc[sz(cc)-1] << ".\n" ; 

	return 0 ;
}