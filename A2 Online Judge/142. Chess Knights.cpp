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
int t , n , m , x , y , c ; 
int di[] = {2 , 2 , -2 , -2 , 1 , 1 , -1 , -1};
int dj[] = {-1 , 1 ,1 , -1 , 2 , -2 , 2 , -2};
vector<vector<bool> > vis; 
#define mp make_pair
int bfs () 
{
	queue<pair<int,int> > q ; 
	pair < int , int > p , fr ; 
	p.first = x ; 
	p.second = y ; 
	vis[x][y] =1;
	q.push(p);
	c=0;
	while ( !q.empty() ) {
		fr = q.front() ; 
		c++ ;
		q.pop() ; 
		for (int i = 0 ; i<8 ; i++)
		{
			int nx = di[i] + fr.first;
			int ny = dj[i] + fr.second ; 

			if (nx >=0 && nx < n && ny >=0 && ny < m ){
				if (!vis[nx][ny] ) {
				vis[nx][ny] = true ;			
				q.push(mp(nx,ny));
				}
			}
		}

	
	}
	return c ;
}
int main()
{
	//freopen("test.in" , "rt" , stdin);
	cin >>t ;
	while (t--) 
	{
		cin >> n >> m >> x >> y ; 
		x--;
		y--;
		vis.clear();
		vis.resize(n ,vector<bool>(m) );	
		cout << bfs()<<endl;
	}
	return 0;
}
