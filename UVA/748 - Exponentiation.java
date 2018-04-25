import java.util.Scanner;
import java.math.BigDecimal;

class Main
{

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);            
        BigDecimal a ;
        String s;
        int  n ;


        while(sc.hasNext())
        {
            a = sc.nextBigDecimal();
            n = sc.nextInt();
            a = a.pow(n);
             s=a.stripTrailingZeros().toPlainString();
            if(s.charAt(0)=='0')
                s=s.substring(1,s.length());
            
            System.out.println(s);
           //System.out.println(r);
        }
      }  
   
  
}
