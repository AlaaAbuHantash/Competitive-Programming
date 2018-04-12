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


//-
//boxes will contain between 1 and 50 elements, inclusive.
//-
//Each element of boxes will contain only digits ('0'-'9') and spaces (' ').
//-
//Each element of boxes will be a single space separated list of integers without leading or trailing spaces.
//-
//Each integer in boxes will not contain leading zeros and will be between 0 and 99, inclusive.
//-
//Each element of boxes will contain between 1 and 14 integers, inclusive (that's the number of different colors used).
//-
//All elements of boxes will contain the same number of integers.
//-
//The number of different colors used will be less then or equal to N, where N is the number of elements in boxes.

//int dp[box][color]  = ????? ???? ?? ???????? 
// 


class MarblesRegroupingHard {
public :
	int dp[51][1<<14], a[51][15] ,nubb,c,n ;

	int minMoves(vector <string> boxes){
		nubb=sz(boxes);
		mem(dp,-1);
		mem(a,0);

		c=0;
		string temp = "";
		rep(i,sz(boxes)) {
			c=0;
			temp="";
			rep(j,sz(boxes[i])){
				if(boxes[i][j] >='0' && boxes[i][j]<='9')
					temp+=boxes[i][j];
				else {
					a[i][c] = inttstr(temp);
					temp="";
					c++;
				}
			}
			a[i][c] =inttstr(temp);

		}
		n=c+1;
		cout << n << endl;
		int res = dpcount (0,0);
		//cout << res << endl;
		return res ;
	}

	int dpcount (int box , int col ) {
		if(col==(1<<n)-1)
			return 0;
		if (box == nubb)
			return oo;
		int res=oo;

		if(dp[box][col]!=-1)
			return dp[box][col];

		rep(i,n) // kol box ba5od color 
		{
			if ( ( ( col>> i) & 1 ) == 1 )
				continue;
			res = min (res, sum(i,box)+ dpcount(box+1, col | (1<<i)) )   ;

		}
		res = min (res, dpcount(box+1,col) );
		return dp[box][col]=res;
	}

	int inttstr (string s ){
		int nub=0;
		rep(i,sz(s)) {
			nub+= (s[i]-'0');
			nub*=10;
		}
		return nub/10;
	}

	int  sum(int x ,int y) {
		int res=0;
		rep(i,nubb) 
			if(i!=y)
				res+=a[i][x];
		return res;

	}
};
int  main()
{
	//freopen("test.in" , "rt" , stdin);
	vector<string> s ; 
	s.pb("77 97");
	s.pb("8 0");
	MarblesRegroupingHard m;
	m.minMoves(s);
	return 0 ;
}