
import java.util.Scanner;   
class Main
{
    public static void main(String[] args) 
    {
        Scanner s = new Scanner(System.in);            
        double r = 0.0  , x; 
        String a;
        int i;
        for ( i= 0 ; i < 12 ; i++)
        {
            x = s.nextDouble();
            r = r + x ; 
        }
       r = r /12;
          a = String.format("%.2f", r);
      
        System.out.println("$" + a);
       
    }
  
}
