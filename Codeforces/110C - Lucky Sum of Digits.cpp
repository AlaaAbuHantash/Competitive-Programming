#include<iostream> 
#include<stdio.h> 
#include<string>
using namespace std ; 
string dp[7005]; 
string comp ( string a , string b ) {
	if ( a.length() == b.length() ) {
		for ( int i = 0 ; i < a.length() ; i++) {
			if ( a[i] > b[i] )  return b ; 
			else if ( a[i] <b[i] ) return a ; 
		} 
	}

	if ( a=="9" && b !="9" ) return b ; 
	if ( a!="9" && b == "9" ) return a ; 
	if ( a == "9" && b == "9" ) return a ; 
	if (a.length() > b.length() ) return b ; 
	return a ; 
}
string calc ( int s   ) {
	if ( s == 0 )  return "" ; 
	if ( dp[s] != "9" )     return dp[s] ; 

	string res = "9" , r = "9" ;
	if ( s - 7 >= 0 )   res= "7" + calc ( s - 7  ) ; 
	if ( s - 4 >= 0 )   r =  "4" + calc ( s - 4   ) ; 

	string v = comp ( r ,res ) ; 
	if ( res == "9"  || (res.find('9') < res.length()  && res.find('9') >=0) ) v = r ; 
	if ( r == "9" || r.find('9') < r.length() && r.find('9') >=0 )  v = res ;
	if ( v== "9"  || (v.find('9') < v.length()  && v.find('9') >=0) )   v="9";

	return dp[s]= v ; 
}
int main () {
 //freopen("test.in" , "rt", stdin) ; 
	int n ; 
	int x  ; 

	for ( int i = 0 ; i < 7005; i++) 
		dp[i]= "9"  ; 
	string res ; 
	//calc ( 10000 ) ; 
	calc (7000 ) ; 
	scanf("%d",&n);

	if ( n <= 7000 ) 
		res = calc (n ); 
	else 	if ( n  > 7000 ) {
			x = n / 7000 ; 
			res = calc ( n - ( x *7000 ) ) ;    
		//	cout << ( n - ( x *7000 )  ) << endl;
			for  ( int i = 0 ; i < x ; i++ ) 
				res += dp[7000];
		}

		if ( res == "9"  || (res.find('9') < res.length()  && res.find('9') >=0) ) 
			printf("-1\n");
		else 
			cout << res << "\n";


}