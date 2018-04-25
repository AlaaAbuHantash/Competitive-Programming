import java.util.Scanner;
import java.math.BigInteger;
class Main
{

    public static void main(String[] args) 
    {
        Scanner s = new Scanner(System.in);            
        BigInteger a[] = new BigInteger[5005];
        a[0] = BigInteger.ONE ; 
        a[1] = BigInteger.valueOf(2);
        a[2] = BigInteger.valueOf(3);
        a[3] = BigInteger.valueOf(5);
        int i , n ;
        for ( i = 4; i <= 5000 ; i++)
            a[i] = a[i-1].add(a[i-2]);

        while(s.hasNext())
        {
            n = s.nextInt();
           System.out.println(a[n]);
        }
      }  
   
  
}
