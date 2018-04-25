
package alaa ;
import java.util.Scanner;
import java.math.BigInteger;
class Main
{

    public static void main(String[] args) 
    {
        Scanner s = new Scanner(System.in);            
        BigInteger  r , a[] = new BigInteger[5005] , x , y ;
        a[0] = BigInteger.ZERO ; 
        a[1] = BigInteger.ONE;
        x = a[0] ; y= a[1];
        int i , n ; 
        for ( i = 2; i <= 5000 ; i++)
        {
            a[i] = x.add(y);
            x = y;
            y = a[i];
        }
        while(s.hasNext())
        {
            n = s.nextInt(); 
            r = a[n];
            System.out.println("The Fibonacci number for "+n+" is "+r);
        }
      }  
   
  
}
