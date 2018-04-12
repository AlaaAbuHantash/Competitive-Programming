#include<iostream>
#include<stdio.h> 
#include<vector> 
using namespace std ; 
 class ChristmasTreeDecorationDiv2 {
 public : 
int solve(vector <int> col, vector <int> x, vector <int> y) {
	int c = 0 ; 
	for ( int i = 0 ; i < x.size() ; i++ ) {
		if ( col[x[i]-1] != col[y[i]-1] ) 
			c++; 

	}
	return  c ; 
}
 };
int main () {

	return 0 ; 
}