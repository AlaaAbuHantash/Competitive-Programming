#include<iostream>
#include<stdio.h>
#include<string>
#include<set>
#include<algorithm>
#include<map> 
#include<vector>
using namespace std ;
vector<string > v ; 
int t , n , m ,  k , r1 , r2 ; 
string s;  
int ck(int x  , int y ) 
{
	string r ; 
	r="";
	for ( int i = y , j = 0  ;i < m && j < s.length() ; i++ , j++ ) 
		r+=v[x][i] ; 
	if ( r == s ) 
		return 1 ; 

	r="";
	for ( int i = y , j = 0  ;i >=0 && j < s.length() ; i-- , j++ ) 
		r+=v[x][i] ; 
	if ( r == s ) 
		return 1 ; 

	r="";
	for ( int i = x , j = 0  ; i <v.size() && j < s.length() ; i++ , j++ ) 
		r+=v[i][y] ; 
	if ( r == s ) 
		return 1 ; 

	r="";
	for ( int i = x , j = 0  ; i >=0 && j < s.length() ; i-- , j++ ) 
		r+=v[i][y] ; 
	if ( r == s ) 
		return 1 ;

	r = "";
	for ( int i = x , j = y  , f = 0  ; i < v.size() && j < m && f < s.length()  ; i++ , j++ , f++ ) 
		r+=v[i][j] ;
	if ( r == s ) 
		return 1 ; 

	r="";
	for ( int i = x , j = y  , f = 0  ; i >=0  && j >=0 && f < s.length()  ; i-- , j-- , f++ ) 
		r+=v[i][j] ;
	if ( r == s ) 
		return 1; 

	r="";
	for ( int i = x , j = y  , f = 0  ; i >=0  && j < m && f < s.length()  ; i-- , j++ , f++ ) 
		r+=v[i][j] ;
	if ( r == s ) 
		return 1 ; 


	r="";
	for ( int i = x , j = y  , f = 0  ; i < v.size()  && j >=0 && f < s.length()  ; i++ , j-- , f++ ) 
		r+=v[i][j] ;
	if ( r == s ) 
		return 1 ; 

	return -1 ; 
}
int main () {

	//freopen("test.in","rt",stdin ); 

	cin >> t ; 
	while(t-- ) {
		cin >> n  >> m ; 
		v.clear();
		while(n--) {
			cin >> s ; 
			for ( int i = 0 ; i < s.length() ; i++) 
				s[i] = tolower(s[i] ) ; 
			v.push_back(s);
		}
		cin >> k ; 
		while(k--){
			cin >> s ; 
			for ( int i = 0 ; i < s.length() ; i++) 
				s[i] = tolower(s[i] ) ; 
			int z =  0 ;
			bool flag = 0 ; 
			for ( int i = 0 ; i < v.size() ; i++) {
				for ( int j = 0 ; j <m ;j++) {
					if (v[i][j] == s[0] ) {
						int z = ck(i,j) ; 
						if ( z == 1  ) {
							cout << i+1 << " " <<j+1 << endl ; 
							flag = 1 ;  
							break; 
						}
					}
				}
				if (flag ){
					break; 
				}
			}
		}
		if(t) printf("\n");

	}
	return 0 ; 
}