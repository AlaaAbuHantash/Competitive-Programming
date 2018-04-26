/**			
***** Judge
******* Yourself 
********* Only   
*/
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
#include<cmath>
using namespace std;
#define mp make_pair
#define eps 1e-6
int fr[30];
int fr2[30];
int main()
{	
	//freopen("a.txt", "rt", stdin);

	int t ; 
	cin >> t ;
	while(t-- ) {
		int  n ; 
		cin >> n ; 
		vector<int >  v ; 
		int x ; 
		for ( int i = 0 ; i < n ; i++ ) {
			cin >> x ; 
			v.push_back(x-1);
		}
		string s ; 
		cin >> s ; 
		vector<int > r ;
		int  sum = 0 ; 
		r.push_back(0) ; 
		for ( int i = 0 ; i < n ; i++ ) {
			int c = 0 ;
			x = v[i] ; 
			int pos = lower_bound(r.begin(),r.end() , x )-r.begin() ; 
			//cout << pos <<   " " << r.size() << endl;
			if(pos == r.size()  || r[pos]!= x ) 
				pos--;
			int st = r[pos] ; 
			int ed ; 
			if(pos+1 == r.size())
				ed = s.size()-1;
			else 
				ed = r[pos+1] -1 ;
		
			memset(fr,0,sizeof(fr));
			memset(fr2,0,sizeof(fr2));
			for ( int j = st ; j<= x ; j++ )
				fr[s[j]-'a'] = 1 ; 
			for ( int j = x+1 ; j<=ed ; j++ ) 
				fr2[s[j]-'a'] = 1 ; 
			for ( int j = 0 ; j < 26 ; j++ ) 
				if(fr[j] + fr2[j] == 1 ) 
					c++ ; 
			//cout << "x " <<  x << " " <<  st << " " << ed  << " c  :" << c << endl; 
			sum+=c;
			r.push_back(x+1);
			sort(r.begin(),r.end());
		}

		cout << sum << endl; 
	}

	return 0;
}