#include<stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main()

{
int N ,i ;
float p[100],sum;

cin >> N;
sum=0;
for(i=0; i<N;i++)
	{

		cin >>p[i];
        sum = sum +p[i];
    }

cout << sum/N<<endl;
return 0 ;
}

