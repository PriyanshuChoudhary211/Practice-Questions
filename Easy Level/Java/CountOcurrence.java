import java.util.*;
public class CountOcurrence {
    public static void main(String[]args)
    {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        String s2 = sc.nextLine();

        int i = 0,j=s.length();
        String str="";
        int count=0;
        while(i<j)
        {
            if(s.charAt(i)==' ')
            {
                if(str.compareTo(s2)==0)
                  count++;
               str="";
               i++;
            }
            str+=s.charAt(i);
            i++;
           
        } 
        if(str.compareTo(s2)==0)
                  count++;
            System.out.println(s2 + " comes: " + count + " times");

       
       sc.close();
    }
}
