#include <iostream>
#include<string>
#include<stdio.h>
using namespace std;

int main() {
    // your code goes here
    int n , x , sum , c=1; 
    cin >> n ; 
    int arr[]= {2 , 3 , 4 , 5 , 6 , 3 , 4 , 5 ,6 , 7 , 4 , 5 , 6 , 7 , 8 , 5 , 6 , 7, 8 , 9, 6 , 7, 8 , 9 , 10 , 7 } ; 
    while(n-- ) {
        string s ; 
        sum=0;
        cin >> s ;
         for( int i = 0 ; i < s.size() ; i++) {
             sum+= arr[s[i]-'A'];
         }
        printf("Case %d: %d\n" , c++ , sum );
    }
    return 0;
}