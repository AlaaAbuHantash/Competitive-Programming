#include<iostream> 
#include<stdio.h>
#include<vector> 
#include<string>
#include<algorithm>
using namespace std ;
int x  , z ; 
vector < string > s ; 
void calc ( int a  ) {
	int b = z - (a * 2); 
	string aa ="" ,bb ="" ,cc = "" ; 
	for ( int i = 0 ; i < b ; i++) 
		cc+=" ";
	for ( int i = 0 ; i < a ;i++){
		aa+= char(i+'0') ; 
		aa+=" ";
	}
	bb = aa ; 
	reverse(bb.begin() , bb.end());
	aa+=char(a+'0');
	cout << cc+ aa +bb<< endl;
	s.push_back(cc+ aa+bb);
}
int main () {
	scanf ( "%d",&x) ; 
	z =x * 2 ; 

	for ( int i = 0 ; i <= x ; i++) 
		calc(i  );
	for ( int i = s.size()-2 ; i >=0 ;i--) 
		cout << s[i] << endl;
	return 0 ; 
}