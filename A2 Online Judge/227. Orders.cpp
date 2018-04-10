#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string>
using namespace std; 
int main() {
	int t ; 
	string s ; 
	scanf("%d",&t) ; 
	while(t--){
		cin >> s ; 
		sort(s.begin(),s.end());
		cout << s << endl;
		while(next_permutation(s.begin(),s.end()))
			cout << s <<"\n";
		
	}
	return 0 ; 
}