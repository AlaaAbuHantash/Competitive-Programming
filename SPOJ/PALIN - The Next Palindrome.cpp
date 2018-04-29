#include <iostream>
#include<string> 
#include<map>
#include<algorithm>
#include<sstream>
#include<vector>
using namespace std;
int main() {
	//freopen("input.in","rt",stdin); 
	//freopen ("myfile.txt","w",stdout);
	string s  , tmp ;
	int t; 

	scanf("%d",&t) ; 
	while(t-- ) {
		cin >> s; 
		bool fin = 0 , g = 0  ;
		tmp = s ;
		int n =s.length() , f = 0 ;
		int ind ; 
		for ( int i = 0 ; i <n /2 + ( n%2 ==0 ? 0:1 )  ;i++) {
			if ( f == 1 && ind <=i ) {
				tmp[n- ind - 1 ]  = s[ind ] ;
				for ( int j = ind +1 ; j <=n- ind - 2;j++) 
					tmp[j] = '0' ; 
				g= 1  ; 
				break;
			}
			else if ( s[i] == s[n-i-1 ] ) 
				continue;
			else if ( s[i]  > s[n-i-1 ] ) {
				tmp[n-i-1 ] = s[i] ; 
			}
			else {
				ind = n-i-2 ; 
				while (1 ) {
					if( ind == 0 || tmp[ind] !='9') 
						break;
					ind--;
				}
				if ( ind == 0  && tmp[0] == '9' ) {
					fin = 1 ; 
					break;
				}
				else {
					s[ind] = s[ind] +1 ;
					tmp[ind] = s[ind] ;
					f = 1 ; 
				}
				tmp[i] = s[i];
				tmp[n-i-1] = tmp[i];
			}
		}
		if ( fin ) {
			tmp = "1";
			for ( int i = 0 ; i <n; i++) 
				tmp +="0" ; 
			tmp[n] = '1' ; 
		}
		else if ( s == tmp ) {
			fin = 0 ; 
			f=5;
			if ( n %2 != 0 ) {
				if ( tmp[n/2] != '9' )
					tmp[n/2]  = tmp[n/2]  +1 ; 
				else {
					int ind = n/ 2 ; 
					while(1) {
						if( ind == 0 || tmp[ind] !='9') 
							break;
						ind--;
					}
					if ( ind == 0  && tmp [0] == '9' ) {
						fin = 1 ; 
					}
					else {
						tmp[ind] = tmp[ind] +1 ; 
						tmp[n-ind-1] = 	tmp[ind];
						for ( int j = ind +1 ; j <= n-ind-2 ;  j ++) 
							tmp[j] = '0' ; 
					}
				}
			}
			else {
				if ( tmp[n/2] != '9' ){
					tmp[n/2]  = tmp[n/2]  +1 ; 
					tmp[n/2-1]  = tmp[n/2-1]  +1 ; 
				}
				else {
					int ind = n/ 2 -1; 
					while(1) {
						if( ind == 0 || tmp[ind] !='9') 
							break;
						ind--;
					}
					if ( ind == 0  && tmp [0] == '9' ) {
						fin = 1 ; 
					}
					else {
						tmp[ind] = tmp[ind] +1 ; 
						tmp[n-ind-1] = 	tmp[ind];
						for ( int j = ind +1 ; j <= n-ind-2 ;  j ++) 
							tmp[j] = '0' ; 
					}

				}
			}
		}
		//else if ( g && n %2 != 0 ) 
		//	tmp[n/2]='0';

		if ( fin && f  == 5 ) {
			tmp = "1";
			for ( int i = 0 ; i <n; i++) 
				tmp +="0" ; 
			tmp[n] = '1' ; 
		}
		cout << tmp << "\n";
	}
	return 0;
}