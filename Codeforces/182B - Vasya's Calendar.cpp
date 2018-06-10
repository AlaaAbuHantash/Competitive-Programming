#include <iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	//freopen("test.in", "rt", stdin ) ; 
	long long int n  , a = 0 , x , c = 0  ; 
	cin >> n >> x ; 
	while(x--) {
		scanf("%d",&a) ; 
		c+= ( n -a ) ; 
	}
	c-= ( n-a); 
	cout << c << endl;
	return 0;
}