#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int di[] = {1 , -1 , 0 , 0 };
int dj[] = {0 , 0 , 1 , -1};
struct node 
{
	int i , j , c ; 
};
int main()
{
	int t  , m , n  , i , j ; 
	node z , y , x; 
	queue<node> q ; 
	vector<string> s ; 
	vector<vector<bool> > v ;
	vector<vector<int > > f ;
	cin >> t ; 
	while (t--)
	{
		cin >> n >> m ; 
		s.resize(n) ; 
		v.resize(n , vector<bool> (m) );
		f.resize(n , vector<int> (m) );

		for ( i = 0 ; i < n ; i ++ )
		{
			cin >> s[i];
			for (j=0 ; j < m ; j++)
				if(s[i][j] == '1')
					{
						z.i =i ; 
						z.j =j ;
						z.c = 0 ;
						q.push(z); 
						v[i][j] = 1  ; 
						s[i][j] = '0' ; 
				    }
		}




		while(!q.empty())
		{
			y = q.front() ; 
			q.pop(); 
			y.c+= 1 ; 
			for(i=0 ; i < 4 ; i++ ) 
			{
				x.i = di[i] + y.i ; 
			    x.j = dj[i] + y.j ; 
				
				if(x.i >=0 && x.i <n && x.j >=0 && x.j < m ) 
				if (!(v[x.i][x.j]))
				{
					v[x.i][x.j] = 1 ; 
					//s[x.i][x.j]+= y.c; 
					f[x.i][x.j]+= y.c; 
					x.c = y.c ;
					q.push(x);
				}

			}


		}

		
			for ( i = 0 ; i < n ; i ++ )
			{
				for ( j = 0 ; j < m ; j++ )
				   {
					   cout << f[i][j] ; 
					   if ( j+1 != m )
						   cout << " " ;
				  }
				cout << endl;
			}

			s.clear() ; 
			v.clear();
			f.clear();
	}
	return 0;
}