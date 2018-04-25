import java.math.BigInteger;
import java.util.Scanner;

class Main
{
    public static void main(String[] args) 
    {
        Scanner s = new Scanner(System.in);
        BigInteger a , n , sum ,x ;
        int i ;
        
       while(s.hasNext())
       {
         
          sum=BigInteger.ONE ; x=BigInteger.ONE ;
          n = s.nextBigInteger();
          a= s.nextBigInteger();

          for (i=1 ;!n.equals(BigInteger.valueOf(i)); i= i+1)
          {
              x=BigInteger.ONE ;
              x = a.pow(i);
              x = x.multiply(BigInteger.valueOf(i));
              sum = sum.add(x);
          }  
           x=BigInteger.ONE ;
           x = a.pow(i);
           x = x.multiply(BigInteger.valueOf(i));
           sum = sum.add(x);
              sum=sum.subtract(BigInteger.ONE);
         System.out.println(sum);
       }
    }
}
