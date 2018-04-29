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

int n ; 
vector<string > s ; 
vector<vector<bool> > vis ; 

int dx[] = {0 , 0 , -1 , 1 , -1 , 1} ; 
int dy[] = {1 , -1 , 0 , 0 , -1 , 1} ; 
bool w ;

void dfs ( int x , int y ) 
{
	if ( vis[x][y] ) 
		return ; 
	vis[x][y] = 1 ; 

	if ( y == n -1 ) {
		w = true;
		return ;
	}

	for ( int i = 0 ; i < 6 ; i++)
	{
		int nx = x + dx[i] ; 
		int ny = y + dy[i] ; 

		if ( nx >= 0 && ny >= 0 && nx < n && ny < n ) 
			if ( !vis[nx][ny] && s[nx][ny] == 'w' ) 
				dfs (nx , ny ) ;
	}
}

int main()
{
	int a = 1 ;

	//freopen("test.in" , "rt" , stdin);
	while (cin >> n ){


		if (  n == 0 ) 
			break;
		s.resize(n);
		vis.clear();
		vis.resize(n , vector<bool > (n)) ;
		for ( int i = 0 ; i < n ; i++)
			cin >> s[i] ;
		w = false ;
		for ( int i = 0 ; i < n ; i++) 
				if ( s[i][0] == 'w' ) {

					dfs(i , 0 ) ;
					vis.clear();
					vis.resize(n , vector<bool > (n)) ;
				}


		if ( w) 
			cout << a++ << " W" << endl;
		else 
			cout << a++ << " B" << endl;
	}

	return 0 ;
}