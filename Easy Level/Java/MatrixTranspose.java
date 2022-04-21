import java.util.*;
public class MatrixTranspose {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of rows and columns for Matrix:");
        int a = sc.nextInt();
        int b = sc.nextInt();
        int arr[][] = new int[a][b];
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                arr[i][j] = sc.nextInt();
            }
        }
        int arr1[][] = new int[a][b];
        for(int i = 0; i<a; i++)
        {
            for(int j = 0 ; j<b ; j++)
            {
                arr1[i][j] = arr[j][i];
            }
        }
        for(int i = 0 ;i<a; i++)
        {
            for(int j = 0 ; j<b ; j++)
            {
                System.out.print(arr1[i][j]+" ");
            }
            System.out.println();
        }
      sc.close();
    }

}
