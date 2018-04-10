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
#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define oo ((int) 1e9)
#define mp make_pair

using namespace std;
int dx[] = {0 ,  0 , 1 ,-1 , 1 , 1 , -1 , -1 } ;
int dy[] = {1 , -1 , 0 , 0 , 1 ,-1 ,  1 , -1 } ;
int  main()
{

	//freopen("test.in" , "rt" , stdin);
	int t , n , c  , a = 1, l ;  
	string s  , u , temp; 
	cin >>t ; 
	map <string , int > m ;
	map <string , int > ::iterator it ; 
	vector<pair<int , string > > p ; 
	while (t--) 
	{
		m.clear();
		p.clear();
		cin >> n >> c ; 
		rep( i , n ) 
		{
			cin >> s ; 
			if ( s =="commented" ) 
			{
				cin >> s >> u >> s ; 
				m[u]++;
			}
			else 
			{
				cin >> u >> s ; 
				m[u]++ ;
			}
		}


		for (  it = m.begin() ; it != m.end() ; it++ ) 
		    p.push_back(mp (m[it->first] , it->first ) ) ; 

		sort(p.rbegin() , p.rend() ) ;

		cout << "Case "<<a++<<":" <<endl;
		for (int i=0; c-- ; i++) 
		{
			l = p[i].second.length();
			temp = (p[i].second ).substr(0 , l - 2);
			cout <<temp <<endl;
		}

	}
	return 0 ;
}

