#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility> 
#include <stack>
#include <cstring> 
#include <functional>
#define  pii  pair < int , pair < int , int > > 

using namespace std;

int h , w ; 
int sx , sy , dx , dy ; 
vector < string >  s ; 
int visit [30][30] ; 
int dxx[] = {0 , -1 , 0 , 1} ;
int dyy[] = {1 , 0 ,-1 , 0 } ;
priority_queue <pii , vector<pii> , greater<pii> >  q ; 

void dik (int sx , int sy , int dx , int dy  )
{
	int i , nx , ny , cost ; 

	pii cur , temp ;
	cur.second.first = sx ; 
	cur.second.second = sy ; 
	cur.first = 0 ; 

	q.push(cur) ; 
	bool o = false ;
	while ( !q.empty() )
	{
		cur = q.top() ;
		q.pop();
		if (visit[cur.second.first][cur.second.second])
			continue;
		//cout << cur.second.first << " " << cur.second.second << " " << cur.first << endl;
		visit[cur.second.first][cur.second.second] = 1 ; 
		
		if (cur.second.first== dx && cur.second.second == dy  )
			{o = true ; break;}

		for (i=0 ; i < 4 ; i++) 
		{
			nx = cur.second.first + dxx[i] ; 
			ny = cur.second.second + dyy[i] ; 
			cost = cur.first ; 

			if ( nx >= 0 && ny >= 0 && ny < w && nx < h  ) 
				if ( s[nx][ny] != 'X' && !visit[nx][ny] ) 
				{
					//cout <<nx << " " << ny<< endl;
					// visit[nx][ny] = 1 ; 
					if(s[nx][ny] != 'D')
						cost = cost +(s[nx][ny] - '0') ;

					// cout << cost << " " <<  cost + s[nx][ny] -'0' << endl;
					 temp.first = cost ; 
					 temp.second.first = nx ; 
					 temp.second.second = ny ; 
					 q.push(temp);
				}

		}
  }
	cout << cur.first << endl;

}
int main()
{
	//freopen("test.in" , "rt" , stdin);
	while ( cin >> w >> h )
	{
		if ( !w && !h)
			break ;
	s.clear();
	s.resize(h+1) ; 
	memset(visit , 0 , sizeof(visit) );
	for ( int i = 0 ; i < h ; i ++ ) 
		{
			cin >> s[i] ; 
			for (int j = 0 ; j < s[i].size() ; j++ ) 
				if ( s[i][j] == 'S')
				{sy = j ; sx = i ;}
				else if ( s[i][j] == 'D')
				{dy = j ; dx = i ;}

	    }
	dik  (sx , sy , dx , dy ) ; 
	
	while(!q.empty() ) 
		q.pop();
	//cout << minn << endl;
	}
	return 0;
}



