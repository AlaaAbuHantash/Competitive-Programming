#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility> 
using namespace std;
int main()
{
  
	long long  s , n , p  ;
    int i; 
	cin >> p >> n ; 

	bool f = true;
	long long  a , b ; 
	vector< pair <long long  , long long  > > p2 (n) ; 
		for ( i=0;i<n;i++)
			{
				cin >>a >> b ; 
				p2[i] = make_pair(a,b);
		    }
	
		sort(p2.begin() , p2.end() ) ;

    for ( i=0;i<n;i++)
            {
				if (p <= p2[i].first)
                     {
						 f=false;
			        	break;
				}
                else 
                    p = p + p2[i].second;
            }



    if( f ) 
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
	return 0;
}