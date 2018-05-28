#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
struct n 
{
	int x ;
	string s2;
};
int main()
{

	string s , t ,r ; 
	n a ;
	int i ;
	map < string , n> m ;
	map < string , int > c ;
	map < string , n > ::iterator it ;
	set <string > fr ; 
	set <string > ::iterator it2 ; 

	cin >> s ;
	a.x = 0 ;
	while ( s != "#")
	{
		t="";
		r = s;
		for (i=0;i<s.length();i++)
		{
			s[i]  = toupper(s[i]);
			t = t + s[i]  ;
		}
		sort(t.begin(), t.end());
		c[t]++;
		a.s2= r ;
		a.x = c[t] ;
		m[t] = a;
		cin >> s ;
	}

	for ( it = m.begin() ; it != m.end() ; it++) 
	{
		if ( m[it->first].x == 1 ) 
			fr.insert( m[it->first].s2 );
		//cout <<it->first <<" " << m[it->first].s2 <<" "<<  m[it->first].x << endl;
	}

	for(it2 = fr.begin() ; it2 != fr.end() ; it2++)
		cout << *it2<<endl;
} 