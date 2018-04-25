import java.math.BigInteger;
import java.util.Scanner;

class Main
{
    public static void main(String[] args) 
    {
        Scanner s = new Scanner(System.in);
        int n  ;
        BigInteger a , b ;
       while(s.hasNext())
       {
          a= s.nextBigInteger();
          b = s.nextBigInteger();
          b =b.multiply(a);
         System.out.println(b);
       }
    }
}
