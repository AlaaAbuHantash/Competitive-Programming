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
/* You got a dream, you gotta protect it.*/ 
using namespace std;
int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ; 
string a,b,t;
int c;
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	cin >> a >> b ;
	c=0;t="";
	sort(a.begin(),a.end());
	for(int i = 0 ; i < a.length() ; i++) 
		if (a[i] == '0'){
			c++;
			t+="0";
		}
		else 
			break;
	a=a.substr(c);
	if (a.length() > 1 ) 
		a = a[0] + t + a.substr(1);
	else if (a.length() ==1 ) 
		a = a[0] + t + a.substr(1);
	else {
		a=t;
	}

	if (a== b ) 
		printf("OK\n");
	else 
		printf("WRONG_ANSWER\n");


	return 0 ;
}
