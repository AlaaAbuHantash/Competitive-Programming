#include<string>
#include<iostream>
#include<stdio.h> 
#include<algorithm>
using namespace std ;
int main () {
	//freopen("test.in","rt",stdin);

	string s ,a  , b , rr , r  ,c ; 
	cin >> s >> a >> b ;
	r= a ; 
	rr= b ; 
	reverse(r.begin() , r.end()) ; 
	reverse(rr.begin(),rr.end())  ; 

	int aa= 0 , bb = 0 , inda , indb ; 
	bool f = 0   , g  = 0 ; 
	for ( int i = 0 ; i < s.length() ; i++) {
		if ( s[i] == a[0]  && !f ) {
			c = s.substr(i,a.size());
			if ( c == a ) {
				f = true; 
				inda = i+a.size() ; 
			}
		}
		else if ( f && s[i] == b[0]  && inda <= i ) {
			c = s.substr(i,b.size());
			if ( c == b ) aa = 1 ; 

		} 

		if ( s[i] == rr[0]  && !g ) {
			c = s.substr(i,rr.size());
			if ( c == rr ) {
				g = true; 
				indb = i + rr.size();
			}
		}
		else if ( g && s[i] ==r[0]  && indb <= i ) {
			c = s.substr(i,r.size());
			if ( c == r ) bb = 1 ; 
		} 
	}

	if ( aa  && bb )
		printf("both\n");
	else if (aa  ) 
		printf("forward\n");
	else if ( bb ) 
		printf("backward\n");
	else 
		printf("fantasy\n");

	return 0 ; 
}