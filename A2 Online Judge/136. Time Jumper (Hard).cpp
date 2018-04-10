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
using namespace std;
int t  , y , n  , x;
vector<int > a ;
set<int > s ; 
set<int > ::iterator it ; 
map < pair <int , int >  , bool > m ; 
 pair <int , int > M ; 
void fun (int i , int sum) 
{
	M.first = i ; 
	M.second = sum ; 
	if ( m[M])
		return ; 
           
	m[M] = 1 ;
	if ( i == n ) 
	{
		if ( sum != 0 ) 
	   s.insert(y + sum); 
		return ;
	}

	 fun (i+1,sum);
	 fun (i+1,sum+a[i]);


}
int main()
{


   // freopen("test.in" , "rt" , stdin);

    cin >> t ;

     while ( t-- ) 
     {
         cin >> y >> n ; 
		 a.clear();
         a.resize(n);

		 for(int i = 0 ; i < n ; i++ )
			 cin >> a[i] ;
          
         fun(0,0);

         for (it = s.begin() ; it != s.end() ; it++ )
                cout <<*it<< endl;

         s.clear();
         m.clear();
     }
    return 0;
}