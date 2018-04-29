#include<iostream> 
#include<string> 
#include<stdio.h> 
using namespace std ; 
int main () {
	//freopen("test.in" , "rt" , stdin ) ;
	string s ;
	int a = 0 , b = 0 , c = 0 , sum  = 0 , z = 0  , sum2 = 0 ; 
	cin >> s ;
	bool f =0  , res = 1 , g = 0  , bb = 0 ; 
	for ( int i = 0 ; i < s.length() ; i++ ) {
		if ( bb ) {
			if ( (  s[i] >= 'a' && s[i] <='z' ) ||  (s[i] >= 'A' && s[i] <='Z'  ) || (s[i] >= '0' && s[i] <='9' ) || s[i] == '_' )    
				sum2++ ; 
			else {
				res  = 0 ; 
				break ; 
			}
			continue ; 
		}
		if ( s[i] == '@'  ) {
			if ( g ) {
				res = 0 ; 
				break; 
			}
			f= 1 ; g = 1 ; 
			if ( a >= 1 && a <= 16 ) 
				continue ; 
			res = 0 ;
			break;
		}
		else if (!f) {
			if ( (  s[i] >= 'a' && s[i] <='z' ) ||  (s[i] >= 'A' && s[i] <='Z'  ) || (s[i] >= '0' && s[i] <='9' ) || s[i] == '_' )    
				a++; 
			else {
				res = 0 ; 
				break;
			}
		}
		else if ( s[i] == '/' ) {
			 bb = 1 ; 
		} 
		else if ( s[i] == '.'  && !bb) {
			if ( c < 1 || c > 16 ) {
				res = 0 ; 
				break; 			
			}
			sum+=c;
			c=0;
		}
		else {
			if ( (  s[i] >= 'a' && s[i] <='z' ) ||  (s[i] >= 'A' && s[i] <='Z'  ) || (s[i] >= '0' && s[i] <='9' ) || s[i] == '_' )    
				c++; 
			else {
				res = 0 ; 
				break; 		
			}
		}
	}

	if ( c < 1 || c > 16 ) 
		res = 0 ; 
	else 
		sum+= c ; 


	if ( sum < 1 || sum >32 )
		res = 0 ; 
	if (sum2 > 16 || (bb == 1 && sum2 == 0 ) ) 
		res = 0 ; 

	if ( res ) 
		printf("YES\n");
	else 
		printf("NO\n");


	return 0 ; 

}