import java.math.BigInteger;
import java.util.Scanner;

class Main
{
    public static void main(String[] args) 
    {
        Scanner s = new Scanner(System.in);
        int n  ;
        BigInteger a , b , sum , ra , rb  ;
        n = s.nextInt();
        while(n != 0)
        {
            n = n - 1;
        ra = BigInteger.ZERO;
        rb = BigInteger.ZERO;
        sum = BigInteger.ZERO;
        a = s.nextBigInteger();
        b = s.nextBigInteger();
        while (a != BigInteger.ZERO)
        {
            ra = ra.multiply(BigInteger.TEN);
            ra = ra.add(a.mod(BigInteger.TEN));
              a = a.divide(BigInteger.TEN );
        }
        
        while (b != BigInteger.ZERO)
        {
            rb = rb.multiply(BigInteger.TEN);
            rb = rb.add(b.mod(BigInteger.TEN));
             b = b.divide(BigInteger.TEN );
        }
        
        rb = rb.add(ra);
        
         while (rb != BigInteger.ZERO)
        {
            sum = sum.multiply(BigInteger.TEN);
            sum = sum.add(rb.mod(BigInteger.TEN));
             rb = rb.divide(BigInteger.TEN );
        }
        
         System.out.println(sum);
       } 
    }
}
