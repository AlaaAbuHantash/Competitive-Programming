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

/*YOU got a DREAM, YOU gotta protect it. */ 

using namespace std;

int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ; 

map < int , int >  v; 
class PeacefulLine {
public : 
	string makeLine(vector <int> x) {
		int res = 0   , r ; 
		for ( int i = 0 ; i <x.size() ; i++)  {
			v[x[i]] ++ ; 
			res = max( res , v[x[i]] ) ;
		}
		r = x.size()- res ; 
		if ( res - r <= 1)
			return "possible";
		else 
			return "impossible";

	}

};
int  main()
{
	//freopen("input.in" , "rt" , stdin);
	//freopen ("myfile.txt","w",stdout);

	return 0 ;
}