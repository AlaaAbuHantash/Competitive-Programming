#include<iostream>
#include<string>
#include <stdlib.h>
#include<stdio.h>
#include<vector>
using namespace std;
#define mp make_pair
int main() {
	int t,a=-1, b=-1, c=-1 , d=-1 ,e=-1;
	cin >> t;
	string s;
	for (int i = 0; i < t; i++) {
		cin >> s;
		if(s=="0")
			a=0;
		else if (s.length()==1 )
			b=atoi(s.c_str());
		else if (s.length() == 2 && s[1] == '0')
			c=atoi(s.c_str());
		else if (s.length() == 2)
			d=atoi(s.c_str());
		else
			e=100;
	}
	vector<int >res ;
	if ( a != -1 )
		res.push_back(0);
	if(b!= -1 && c!=-1){
		res.push_back(b);
		res.push_back(c);
	}
	else if ( b!= -1 )res.push_back(b);
	else if ( c!= -1 )res.push_back(c);
	else if ( d != -1 )	res.push_back(d);

	if(e != -1 )res.push_back(e);
	printf("%d\n",res.size());
	for(int i = 0 ; i < res.size() ; i++)
		printf("%d ",res[i]);
	return 0;
}
