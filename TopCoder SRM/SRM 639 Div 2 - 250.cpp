#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std ; 
class ElectronicPetEasy  {
public : 
	string isDifficult(int st1, int p1, int t1, int st2, int p2, int t2) {
		vector < int > v ; 
		bool f =  0 ; 
		int x = 0  ,res = 0 ; 
		for ( int i = 0 ; i < t1 ; i++) {
			x = i * p1 ; 
			res = x + st1 ; 
			v.push_back(res ) ; 
		}
		for ( int i = 0 ; i < t2 ; i++) {
			x = i * p2 ; 
			res = x + st2 ; 
			for ( int j = 0 ; j < v.size() ; j++) {
				if ( v[j] == res ) 
					f= 1 ; 
			}
	
		}
		if ( f ) return "Difficult";
		else return "Easy";

	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor