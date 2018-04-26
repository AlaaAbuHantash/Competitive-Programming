#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

    int result[200], e[200][200], v[200] ;
	int   j , m , n  , z; 

void DFS(int i )
{
	int a ; 

 	for (a = 1  ; a <= n ; a++ )
	    if( e[i][a] == 1  && v[a]==0)
		 {
			 v[a] = 1;
			// cout <<v[a]<<a<<endl;
			 DFS(a);
	      }

	result[z--] = i;
}

int main()
{
	int   i ;
	cin >> n >> m ; 
	while (1) 
	{
	if ( n == 0 )
			break ; 

	i= 0 ; 
	while (i <= n )
	{
	   for (j = 0 ; j < n ; j++ )
		e[i][j] = 0 ;
		result[i]=0;
		v[i]=0;
		i++;
	}

	for (z = 0 ; z < m ; z++ )
	{
	cin >> i >> j ; 
	e[i][j] = 1 ; 
	}

	z = n ;

	for (i = 1 ; i <= n ; i++ )
		if (v[i] ==  0)
		{
			v[i] = 1;
			DFS(i);

		 }
		
	/*
	z = 1 ; 
	for (i = 1 ; i <= n ; i++ )
		if ( count[i] == 0  && v[i] == 0)
		{ result[z] = i ; z++ ; }

    */


	    for (z = 1; z <= n ; z++ )
		cout << result[z] << " "; 
		cout << endl ;

	//e.clear();
	//result.clear();
	//count.clear(); 

	cin >> n >> m ; 

	}

	

  return 0;
}
