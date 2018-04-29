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
#include <math.h>
#include<cstdio>
#include<deque>
#include<sstream>

/*YOU got a DREAM, YOU gotta protect it. */ 

using namespace std;
int  main()
{
	string s ; 
	int a ;
	vector< int >  v , p  , res  ;
	//freopen("input.in" , "rt" , stdin);
	//freopen ("myfile.txt","w",stdout);
	while(getline(cin , s )) {
		istringstream A(s) ; 
		p.clear();
		res.clear();
		v.clear();

		while(A >> a ) {
			v.push_back(a) ;
		}
		p = v ; 
		sort(p.begin() , p.end());

		for ( int i = v.size()-1 ; i>=0 ; i--) {

			if ( v[i] == p[i] ) continue;
			int r = -1 ; 
			for ( int j = i ; j>=0 ; j-- ){
				if ( v[j] == p[i] ) {
					r = j ; break;
				}
			}
			if ( r != 0 ) {
				// reverse ( 0 , r ) ; 
				reverse(v.begin() , v.begin() + r+1 ) ;
				res.push_back(v.size() - r  ) ;
				// reverse (0 , i ) ; 
				reverse(v.begin() , v.begin() + i+1 ) ;

				res.push_back(v.size() - i) ;
			}
			else {
				// reverse (0 , i ) 
				reverse(v.begin() , v.begin() + i+1 ) ;
				res.push_back(v.size() - i  ) ;
			}
		}
		res.push_back(0 ) ;

		cout << s<<"\n";
		printf("%d" , res[0] ) ; 
		for ( int i=1;i<res.size() ;i++) 
			printf(" %d",res[i]);
		printf("\n");
	}

	return 0 ;
}