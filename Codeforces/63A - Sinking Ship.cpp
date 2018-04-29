#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include<string>
using namespace std;
int main()
{
	int n , j , k , i , sr  = 0, sm  = 0, sw  = 0, sc = 0 ; 
	cin >> n ; 
	string a;
	vector <string> s(n);
	vector <string> r;
	vector <string> w;
	vector <string> m;
	vector <string> c;
	for ( i = 0 ; i < n ; i++ ) 
		{
			cin >> s[i] >> a ; 
			if ( a == "rat" ) { r.push_back(s[i]) ; sr++;  } 
			else if ( a== "woman"  || a== "child"  ) {  w.push_back(s[i]) ; sw++; } 
			else if ( a== "man" ){  m.push_back(s[i]) ; sm++ ;} 
			else if ( a== "captain" ) { c.push_back(s[i]) ; sc++;} 
	}


	            for ( i = 0 ; i < sr; i++ ) cout << r[i] << endl; 
				for ( i = 0 ; i < sw; i++ ) cout << w[i] << endl;	
				for ( i = 0 ; i < sm; i++ ) cout << m[i] << endl;	
				for ( i = 0 ; i < sc; i++ ) cout << c[i] << endl;
}
