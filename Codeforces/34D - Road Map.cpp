#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility> 
#include <stack>
using namespace std;

int n , r2  ; 
vector< vector<int> > adj ;
vector<bool> v  ; 
vector<int > re; 

void dfs(int x )
{

	v[x] = 1 ;
	for(int i=0 ; i< adj[x].size() ; i++)
		if(!v[adj[x][i]]) 
		{
			//cout << adj[x][i] << " " << x << endl;
			/*
			if ( z == adj[x][i] ) 
			{
				cout << x <<" " ;
				//break;
			}
			*/
			re[adj[x][i]] = x ; 
			dfs(adj[x][i] );

		}

	
}
int main()
{
	int r1 , x , i  ; 
	cin >> n >> r1 >> r2 ; 
	adj.resize(n+1) ;
	re.resize(n+1) ;
	v.resize(n+1) ;

	for ( i = 1 ; i <= n ; i++ ) 
	{

		if( i == r1)
			{
				
				continue;
		    }
		cin >> x ; 
		adj[x].push_back(i);
		adj[i].push_back(x);
	}
	
	dfs(r2);
	int r = 0;
	for( r= 1 ; r <= n ; r++) 
	{
		if ( r == r2 ) 
			continue;
		cout << re[r] << " " ;
		//v.clear() ; 
		//v.resize(n+1);
	}

	cout << endl;

	return 0;
}

/*

6 2 4
6 1 2 4 2

*/