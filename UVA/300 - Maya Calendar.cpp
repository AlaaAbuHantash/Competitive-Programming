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
#include <cmath>
#include <stdio.h>
#include <string.h>

#define sz(v) ((int)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);i++)
 
#define oo ((int) 1e9)
#define mp make_pair

using namespace std;
int main()
{
	//freopen("test.in" , "rt" , stdin);

	//  were pop, no, zip, zotz, tzec, xul, yoxkin, mol, chen, yax, zac, ceh, mac, kankin, muan, pax, koyab, cumhu.
	//The last month of Haab was called uayet and had 5 days
	//Tzolkin 

	 // imix, ik, akbal, kan, chicchan, cimi, manik, lamat, muluk, ok, chuen, eb, ben, ix, mem, cib, caban, eznab, canac, ahau and 13 

	 int t  , d , y  , r , i , m2; 
	cin >> t ; 
	string s1[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol", "chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu", "uayet"},
		s2[]={"imix","ik","akbal","kan","chicchan","cimi", "manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib", "caban","eznab","canac","ahau"} ;
	char ch ; 
	string m ; 
	cout <<t <<endl;
	while ( t--) 
	{
		cin >> d >> ch >> m >> y ;

		for ( i = 0 ; i < 19 ; i++)
			if(s1[i] == m ) 
				break;
		//if ( i == 18 ) 
		//	m2 = 17 * 20 + 5 ; 
		//else 
			m2 = i * 20 ; 
		r = y*365  + d + m2;
		// 13 * 20 = 260 
		y = r / 260 ;
		r = r % 260 ; 
		d = r % 13 ;
		
		m = s2[r%20] ;
		d++;
		cout << d << " " << m << " " << y <<endl;
	}


	return 0;
}