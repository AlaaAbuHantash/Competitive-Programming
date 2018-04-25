import java.math.BigInteger;
import java.util.Scanner;
        
class Main
{
    public static void main(String[] args) 
    {
        Scanner s = new Scanner(System.in);
        BigInteger x , n ,r , m  ;
        int i ; 
        while(true)
        {
           n = s.nextBigInteger() ; 
           if (n.toString().equals("0"))break;
           x = n.mod(BigInteger.TEN);
           n = n.divide(BigInteger.TEN);
           x = x.multiply(BigInteger.valueOf(5));
           r = n.subtract(x);
           m= r.mod(new BigInteger("17"));
           if (m.toString().equals("0"))
                 System.out.println(1);
           else 
                System.out.println(0);
        }
       
    }
}
