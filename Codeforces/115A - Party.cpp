#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility> 
#include <stack>
using namespace std;
int main()
{
	int n , i  , k , max ;
	cin >> n ; 
	vector <vector < int > > arr ;
	arr.resize(n+1);
	vector <bool >  v ( n+1 ) ;
	vector <bool >  v2 ( n+1 ) ;

	for ( i = 1 ; i <= n ; i++ ) 
	{
		cin >> k ;
		if ( k == -1 ) 
			continue ; 
		arr[k].push_back(i);
		v2[i] = 1 ;
		v2[k] = 1;
		// << i << endl;
	}

	max = 0;
	queue <int > q ; 
	int b = 1 ; 
	int c = 0 ;
	for (i = 1 ; i <= n ; i++ )
	{
		c=0;
		if ( !v[i] && v2[i] )
		{
			q.push(i);

	while (!q.empty()) 
	{
		
		int s = q.size();

		//cout << s << endl;
		while(s--)
		{
			b = q.front() ; 
			v[b] = 1 ;
		//	cout << b << endl;
		    q.pop();
		for (i = 0; i <arr[b].size(); i++ ) 
				q.push(arr[b][i]) ;

		}
		
		c++;
	}
		
	}

	//cout << c << endl;
	if ( c > max ) 
		max = c ; 
	}
	if ( max == 0 ) 
		max=1;
	cout << max << endl;
	return 0;
}
