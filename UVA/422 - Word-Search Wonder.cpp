#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std; 
vector<string>v;
int n ; string s ; 
int r1 ,r2 ; 
bool ckt ( int x , int y ) {
	int len = s.length();
	string r = "";
	for ( int i =x , j =0;  i < n && j <len ; i++ , j++) { r+=v[i][y]   ; r1 =  i ; r2 = y ;  } ; 
	if ( r == s ) return true; 

	r = "";
	for ( int i =x , j =0;  i >=0 && j <len ; i-- , j++) { r+=v[i][y]  ; r1 =  i ; r2 = y ;  }
	if ( r == s ) return true; 

	r = "";
	for ( int i =y , j =0;  i >=0 && j <len ; i-- , j++)  {r+=v[x][i]  ; r1 =  x ; r2 = i ; }
	if ( r == s ) return true; 

	r = "";
	for ( int i =y , j =0;  i <n && j <len ; i++ , j++){  r+=v[x][i]  ; r1 =  x ; r2 = i ; }
	if ( r == s ) return true; 

	r=""; 
	for ( int i=x , j = y  , k = 0 ; i < n && j < n && k < len ; i++ , j++ , k++) { r+=v[i][j] ; r1 = i ; r2 = j ;}
	if ( r == s ) return true; 

	r=""; 
	for ( int i=x , j = y  , k = 0 ; i >=0 && j >=0 && k < len ; i-- , j-- , k++) { r+=v[i][j] ; r1 = i ; r2 = j ;}
	if ( r == s ) return true; 

	r=""; 
	for ( int i=x , j = y  , k = 0 ; i >=0 && j < n && k < len ; i-- , j++ , k++) { r+=v[i][j] ; r1 = i ; r2 = j ;}
	if ( r == s ) return true; 

	r=""; 
	for ( int i=x , j = y  , k = 0 ; i < n && j >=0 && k < len ; i++ , j-- , k++) { r+=v[i][j] ; r1 = i ; r2 = j ;}
	if ( r == s ) return true; 

	return false ;
}
int main () {
	freopen("test.in", "rt", stdin);
	scanf("%d",&n) ; 
	for(int i=0;i<n;i++){
		cin>>	s ; 
		v.push_back(s);
	}
	cin >> s ; 
	bool g = 0 ; 
	while ( s !="0") {
		g=0;
		for ( int i = 0 ; i < n ; i ++ ) {
			for ( int j = 0 ; j < n ; j ++) {
				if(v[i][j] == s[0]) {
					if ( ckt(i,j)) {
						printf("%d,%d %d,%d\n",i+1,j+1, r1+1,r2+1 );
						g=1;
						break;
					} 
				}
			}
			if(g)break;
		}
		if(!g)printf("Not found\n");
		cin>>s;
	}
	return  0;
}