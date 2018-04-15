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
int n ;
vector<pair<int , int > > v ; 
double dp[1<<16][16];
int vis[1<<16][16];
double calc(int msk, int ind){
	if(ind >= n ) {
	
		if(msk == ((1<<n)-1)) 
			return 0 ; 
		return 2e9;
	}
	if(vis[msk][ind] != -1 ) 
		return dp[msk][ind];
	double res = 2e9;
	if(!((msk>>ind)&1))
		for ( int i = 0 ; i < n ; i++ ) {
			if(((msk>>i)&1) || ind == i)
				continue; 
			double x = sqrt(( (v[i].first-v[ind].first)* (v[i].first-v[ind].first) ) + ((v[i].second-v[ind].second)* (v[i].second-v[ind].second) )); 
			res = min ( res , (calc(msk|(1<<i) |(1<<ind) , ind+1 ) +x ));

	}

	res = min ( res , calc(msk,ind+1)) ; 
	vis[msk][ind] = 1 ; 
	return dp[msk][ind]= res;
}
int main(){

	///freopen("a.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);
	int t = 1 ; 
	while(cin >> n &&n ) { 
		n*=2 ; 
		memset(vis,-1,sizeof(vis));
		v.clear();
		for ( int i = 0 ; i < n ; i ++ ){
			string s ; 
			int a , b ; 
			cin >> s >> a >> b ; 
			v.push_back(mp(a,b));
		}
		printf("Case %d: %.2lf\n",t++,calc(0,0));

	}
	return 0;
}