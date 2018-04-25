import java.util.*;
public class Main
{
    public static void main(String[] args) 
    {
        Scanner s = new Scanner(System.in);            
        int n , x , i , min , max , c = 0 ; 
         n = s.nextInt() ; 
          x= s.nextInt()  ; 
        min = x ;
        max = x ; 
        for ( i= 1 ; i < n ; i++)
        {
             x = s.nextInt() ; 
            if ( x > max )
            {
                c = c+1 ; 
                 max = x;
            }
            else if (x< min )
            {
                c=c+1;
                min = x ;
                
            }
        
        }
        System.out.println(c);
       
    }
  
}
