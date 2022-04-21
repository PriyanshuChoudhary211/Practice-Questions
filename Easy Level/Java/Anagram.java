import java.util.*;
public class Anagram {
    public static void main(String [] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter string first");
        String s1 = sc.nextLine();
        System.out.println("Enter String second");
        String s2 = sc.nextLine();

        char arr1[] = s1.toCharArray();
        char arr2[] = s2.toCharArray();

        Arrays.sort(arr1);
        Arrays.sort(arr2);

        s1 = new String(arr1);
        s2 = new String(arr2);

        if(s1.compareToIgnoreCase(s2)==0)
        System.out.println("Strings are anagram");
        else 
        System.out.println("String are not anagram");


   sc.close();
    }
}
