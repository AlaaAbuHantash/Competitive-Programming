/**			
***** Judge
******* Yourself 
********* Only   
*/
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
#include <math.h>
#include<cstdio>
#include<deque>
#include<sstream>
#include<cmath>
using namespace std;
#define mp make_pair
#define eps 1e-6
map<string , char > st ; 


int main(){

	//freopen("a.txt", "rt", stdin);
	//freopen("output.txt", "w", stdout);
	/*string a , b ; 
	while(cin >> a >> b ) {
	cout << "st[\"" << b << "\"]= \'" << a <<"\';" << endl;
	
	}
	*/


	st[".-"]= 'A';
	st[".---"]= 'J';
	st["..."]= 'S';
	st[".----"]= '1';
	st[".-.-.-"]= '.';
	st["---..."]= ':';
	st["-..."]= 'B';
	st["-.-"]= 'K';
	st["-"]= 'T';
	st["..---"]= '2';
	st["--..--"]= ',';
	st["-.-.-."]= ';';
	st["-.-."]= 'C';
	st[".-.."]= 'L';
	st["..-"]= 'U';
	st["...--"]= '3';
	st["..--.."]= '?';
	st["-...-"]= '=';
	st["-.."]= 'D';
	st["--"]= 'M';
	st["...-"]= 'V';
	st["....-"]= '4';
	st[".----."]= '\'';
	st[".-.-."]= '+';
	st["."]= 'E';
	st["-."]= 'N';
	st[".--"]= 'W';
	st["....."]= '5';
	st["-.-.--"]= '!';
	st["-....-"]= '-';
	st["..-."]= 'F';
	st["---"]= 'O';
	st["-..-"]= 'X';
	st["-...."]= '6';
	st["-..-."]= '/';
	st["..--.-"]= '_';
	st["--."]= 'G';
	st[".--."]= 'P';
	st["-.--"]= 'Y';
	st["--..."]= '7';
	st["-.--."]= '(';
	st[".-..-."]= '"';
	st["...."]= 'H';
	st["--.-"]= 'Q';
	st["--.."]= 'Z';
	st["---.."]= '8';
	st["-.--.-"]= ')';
	st[".--.-."]= '@';
	st[".."]= 'I';
	st[".-."]= 'R';
	st["-----"]= '0';
	st["----."]= '9';
	st[".-..."]= '&';

	int n ; 
	cin>> n ; 
	cin.ignore();
	string s ; 
	for ( int i = 0 ; i < n ; i++ ) {
		if(i!=0)
			puts("");
		printf("Message #%d\n",i+1);
		getline(cin,s);
		string tmp = "";
		bool f = 0 ; 
		for ( int i = 0 ; i < s.length() ; i++ ) {
			if(s[i] == '.' || s[i] == '-') 
				tmp+=s[i] ,f=0;
			else {
				if(tmp.size())
					cout << st[tmp] ;
				if(f){
					cout<<s[i];
					f=0;
				}
				tmp = "" ; 
				if(!f)
				f=1;
			}
		}

		if(tmp.size())
				cout << st[tmp] ;
		if(s.size() >=2 && s[s.size() -1] == ' ' && s[s.size() -2] == ' ')
			cout<<s[s.size()-1];
		puts("");
	}
	return 0;
}