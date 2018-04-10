#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<map>
using namespace std ; 
int t ,n ,x , m , k ;
int main () {
	//freopen("test.in","rt",stdin);
	scanf("%d",&t) ; 
	int c = 1 , z = 1 ; 
	map < string , int >  mm ; 
	vector<pair < string , string > > v ; 
	vector<int > frq;
	vector<string > res ;
	string a , b ; 
	while(t--){
		scanf("%d%d%d",&n,&m,&k) ; 
		mm.clear();
		v.clear();
		frq.clear();
		frq.resize(105);
		res.clear();
		z= 1 ; 
		while ( n-- ) {
			cin >> a >> b ; 
			if(mm[b] == 0 ) 
				mm[b] =z++;
			v.push_back(make_pair(a , b ) ) ;
		}
		printf("Case %d:\n" , c++);
		for ( int i = 0 ; i < v.size() ; i++) {
			if ( frq[mm[v[i].second] ] < m ) {
				res.push_back(v[i].first) ; 
				frq[mm[v[i].second]]++;
			}
		}
	
		for ( int i  = 0 ; i < res.size() &&  k-- ; i++)
			cout << res[i] << "\n";
	}
	return 0 ;
}