#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility> 
#include <stack>
using namespace std;

	int n , m  , i , k  , j  , c = 0 , y , c2  ;

	vector< vector < int > > adj (101 , vector <int> ( 101) ) ;
	vector<bool> v ( 101 ) ;
	vector<bool> v2 ( 101 ) ;

void dfs (int x ) 
{
	v[x] = 1 ; 
	//cout << x  << "SD " << endl;
	//c2++;
	//cout << c2 << endl;
	for(int i=1 ; i<= m ; i++)
		if(adj[x][i] && !v[i]) 
			dfs(i);
	

}
int main()
{
	int x ;
	cin >> n >> m ; 
	for (i=0 ; i < n ; i++) 
	{
		cin >> k ; 
		if ( k == 0 ) 
			c++ ; 
		else 
			{
				cin >> x ; 
				v2[x] = 1 ;
				for ( j = 1 ; j < k ; j++)
				{
					cin >> y ; 
					//cout << x << y << endl;
					
					v2[y] =1 ; 
					adj[x][y] = 1 ;
					adj[y][x] = 1 ;
					x=y;
				}
		    }
	}


	c2 = 0 ;
	int c3 = 0 ;
	for(x=1 ; x <= m ; x++) 
		if (!v[x] && v2[x])
		{
			//cout <<x << endl;
			dfs(x);
			c3++;
			//cout << c3 <<endl;
		}

		int r = c3 - 1 + c ; 

		if ( c == n ) 
			r++;
	//	cout << c3 << " " << c << endl;
		cout << r << endl;
	return 0;
}