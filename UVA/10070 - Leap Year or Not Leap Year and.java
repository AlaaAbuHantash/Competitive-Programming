import java.util.Scanner;
import java.math.BigInteger;

class Main
{

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);            
        boolean leap , h , b , o = false , f ; 
        BigInteger n ; 

       
        while(sc.hasNext() )
        {
             
            if (o == true)
                System.out.println();
             n = sc.nextBigInteger();
            o = true;
            leap = false;
            f = false ;
            if((n.mod(BigInteger.valueOf(4)).compareTo(BigInteger.ZERO) == 0) && (n.mod(BigInteger.valueOf(100)).compareTo(BigInteger.ZERO)) != 0  ||  (n.mod(BigInteger.valueOf(400)).compareTo(BigInteger.ZERO)) == 0 )    
            {
                leap = true;
                f = true;
                System.out.println("This is leap year.");

            }
             if(n.mod(BigInteger.valueOf(15)).compareTo(BigInteger.ZERO) == 0 )  
             {
                 f= true;
                 System.out.println("This is huluculu festival year.");

             }
              if((n.mod(BigInteger.valueOf(55)).compareTo(BigInteger.ZERO) == 0 ) && leap == true ) 
              { 
                  f= true;
                  System.out.println("This is bulukulu festival year.");
              }
              
              
              if ( f == false) 
                  System.out.println("This is an ordinary year.");

              
              
       }
        
    }
  
}
