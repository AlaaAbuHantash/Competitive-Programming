#include <iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
  //  freopen("test.in", "rt", stdin ) ; 
    long long int n,m,c = 0 , x  , lst ;  
    scanf("%I64d",&n) ; 
    scanf("%I64d",&lst) ;
    n--;
    while(n--) {
        scanf("%I64d",&m) ; 
        x = m - lst + c  ;
        if ( x >= 0 )
            lst = m + c ;
        else {
            c+=(-1*x );
        }
    }
    cout << c << endl;
    return 0;
}