import java.math.BigInteger;
import java.util.Scanner;

class Main
{
    public static void main(String[] args) 
    {
        Scanner a  = new Scanner(System.in);
        BigInteger n = BigInteger.ZERO ; 
        BigInteger t = BigInteger.ZERO ; 
        BigInteger s = BigInteger.ZERO ; 
        while(true)
        {
          n = a.nextBigInteger();
          s = s.add(n);
          if (n.equals(t))
          break;
        }
        System.out.println(s);
    } 
}
