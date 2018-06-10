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
using namespace std;
int main()
{

	//freopen("test.in" , "rt" , stdin);
	int n  , m , k  , x  ,c , c2   , nov; 
	queue < pair < int , int > > q ; 
	cin >> n >> m ; 
	vector <bool > vis (n+1) ; 
	vector < vector < int > > a ; 
	a.resize(m);
	for ( int i = 0 ; i < m ; i++ ) 
	{
		cin >> k ; 
		for ( int j = 0 ; j < k; j ++ ) 
		{
			cin >> x;
			a[i].push_back(x);
			vis[x] =1 ;
		}
	}

	c=1 ; 

	for(int i = 0 ; i< m ; i ++ ) 
	{
		for (int j = 0 ; j < a[i].size() ; j++)
		{
			if ( a[i][j] != c  ) 
			{

				if (!vis[c])
				{
					q.push (make_pair ( a[i][j] , c) ) ;
					vis[c] = 1 ; 
					vis[a[i][j]] = 0 ; 
					a[i][j] = c ;
				}
				else 
				{
					c2 = 1 ;
					bool ou = false;
					for ( int s = 1; s <= n ; s ++  ) 
							if ( !vis[s] ) 
							 {
								 nov = s ;
								 break;
							}
					for(int k = 0 ; k < m ; k++ )
					{
						for (int  g = 0 ; g < a[k].size() ; g++)
							{
								if (a[k][g] == c ) 
								{
									vis[nov] = 1 ; 
									vis[a[k][g]] = 1 ;
									vis[ a[i][j]] = 0 ; 
									q.push (make_pair ( a[k][g] , nov) ) ;
									a[k][g] = nov ;
									q.push (make_pair ( a[i][j] , c) ) ;
									a[i][j] = c ; 

									ou = true;
									break;
								}
								
								c2++;
							}
						     if(ou)
								break;
				     }
				}
			}
			c++;
		}
	}

	pair<int ,int > fr ; 
	cout << q.size()<<endl;
	while (!q.empty() ) 
	{
		fr = q.front() ; 
		cout << fr.first << " " << fr.second << endl;
		q.pop();
	}
	return 0;

}
