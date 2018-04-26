#include <iostream>
#include <vector > 

using namespace std;

int main()
{
int n ,a ,b ,i ,x,sum =0;
cin >> n ; 
 vector <int>d(n-1);
 for (i=0 ; i<n-1 ; i++  ) 
    cin >> d[i]; 

 cin >> a >> b ;
 
 x= b-a; 
 
 for (i=a; i<b ; i++  ) 
   sum = sum + d[i-1];
 
 cout <<sum << endl;
 
   return 0;
}


