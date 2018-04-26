#include <iostream>
#include <vector>
#include <algorithm>
 using namespace std;


 unsigned long calc(unsigned long n);

 int main ()  
 {
	 int i=1 , j ,   m =0;
	 vector<int> temp;
	 int old_i,old_j;
	while (true)
		{
			cin>>i;
			cin>>j;
			if (cin.fail())
				break;

		
			old_i=i,old_j=j;

	   if ( i > j ) swap (i, j);
		 

	   temp.clear();

			 while ( i <= j )
			 {	 temp.push_back(calc(i));
			 
			      i++;
			 
			 }
			  m = *max_element(temp.begin(), temp.end());
		 cout << old_i<<" "<<old_j<<" "<<m<<endl;
	}	return 0;
     
 }

 unsigned long calc(unsigned long n)
 {
  unsigned long c = 1;
    while (n != 1)
    {if (n % 2 == 0)
            n = n/2;
        else
            n = 3*n + 1;
        c++;
    }

    return c;
 
 }

