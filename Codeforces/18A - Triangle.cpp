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
vector<int> x;
vector<int> y;
int dx[] = {0,0,1,-1} ;
int dy[] = {1,-1,0,0};
int s1 , s2 , s3 ; 
bool isT (int a , int b , int c , int d , int e  , int f ) 
{
	s1 = (a-c) * (a-c )+ (b-d ) * (b-d ) ; 
	s2 = (a-e) * (a-e )+ (b-f ) * (b-f) ; 
	s3 = (c-e) * (c-e )+ (d-f ) * (d -f) ; 

	if ( s1 && s2 && s3  && (s1 + s2 == s3 ||  s2 + s3 == s1 || s1 + s3 == s2 ) )
		return 1 ; 
	return 0 ;

}
int main()
{
	//freopen("test.in" , "rt" , stdin);
	bool t = 0 , al = 0 , t2 = 0;
	x.resize(4) ;
	y.resize(4) ;
	cin >> x[1]  >> y[1] >> x[2] >> y[2] >> x[3] >> y[3] ;

	

	if ( isT (  x[1] , y[1], x[2] , y[2], x[3], y[3] ) ) 
		t = true;

	for ( int i = 0 ; i < 4 ; i ++) 
	{
	  al  = isT (  x[1]+dx[i] , y[1]+dy[i], x[2] , y[2], x[3], y[3] ) ;
	  if ( al ) 
		  t2 = 1;
	  al  = isT (  x[1] , y[1], x[2]+dx[i] , y[2]+dy[i], x[3], y[3] ) ;
	  if ( al ) 
		  t2 = 1 ;
	  al  = isT (  x[1] , y[1], x[2] , y[2], x[3]+dx[i], y[3]+dy[i] ) ;
	  if ( al ) 
		  t2 = 1 ;
	}


	if (t) 
		cout<< "RIGHT" << endl;
	else if (t2) 
		cout << "ALMOST" << endl;
	else 
		cout << "NEITHER" << endl;
	return 0;
}