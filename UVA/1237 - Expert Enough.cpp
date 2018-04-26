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
int main(){

	//freopen("a.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);

	int t ; 
	scanf("%d",&t);
	vector<pair<int , pair < int , string > > > v;
	int g = 0 ;
	while ( t-- ) {
		if(g) 
			puts("");
		g=1;
		int d ;
		v.clear();
		scanf("%d",&d);
		string s ; 
		int a , b ; 
		for ( int i = 0; i< d ; i++ ) {
			cin >> s;
			scanf("%d%d",&a,&b);
			v.push_back(mp(a,mp(b,s))) ;
		 }
		
		sort(v.begin() ,v.end()) ;
		int q ; 
		scanf("%d",&q);
		for ( int i = 0 ; i < q; i++ ) {
			int p ;
			
			scanf("%d",&p);	
			int f = 0 , ind = -1 ; 
			for ( int j = 0 ; j < v.size() ; j++ ) {
				if(p < v[j].first   || f > 1 ) 
					break; 
				if ( p>=v[j].first && p<=v[j].second.first) 
					f++ , ind  = j  ;
			}
			if(f==1 ) 
				cout << v[ind].second.second << endl; 
			else 
				puts("UNDETERMINED");

		}

	}
	
	return 0;
}