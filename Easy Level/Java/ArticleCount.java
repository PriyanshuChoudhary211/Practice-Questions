import java.util.*;
public class ArticleCount {
    public static void main(String [] args)
    {
        Scanner sc = new Scanner(System.in);
         String s = sc.nextLine();
         int i = 0, j = s.length();
         int a=0,an=0,the=0;
         String sb="";
         while(i<j)
         {
            
            if(s.charAt(i)==' ')
            {
             if(sb.compareToIgnoreCase("a")==0)
                 a++;
             else if(sb.compareToIgnoreCase("an")==0)
               an++;
              else if(sb.compareToIgnoreCase("the")==0)
              the++;
              sb="";
              i++;
            }
            if(i<j)
            sb+=s.charAt(i);
            i++;  
         }
         if(sb.compareToIgnoreCase("a")==0)
                 a++;
             else if(sb.compareToIgnoreCase("an")==0)
               an++;
              else if(sb.compareToIgnoreCase("the")==0)
              the++;
         System.out.println("a --> "+a + "\nan --> "+an+"\nthe --> "+ the);
         sc.close();
    }
}

