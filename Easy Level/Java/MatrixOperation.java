import java.util.*;

public class MatrixOperation {

    public static void addTwoMatrix(int arr[][], int a, int b, int arr1[][], int a1, int b1) {
        int arr2[][] = new int[a][b];
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                arr2[i][j] = arr[i][j] + arr1[i][j];
            }
        }
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                System.out.print(arr2[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void subtTwoMatrix(int arr[][], int a, int b, int arr1[][], int a1, int b1) {
        int arr2[][] = new int[a][b];
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                arr2[i][j] = arr[i][j] + arr1[i][j];
            }
        }
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                System.out.print(arr2[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void multi(int arr[][], int a, int b, int arr1[][], int a1, int b1) {
        if (b == a1) {
            int arr2[][] = new int[a][b1];
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < b1; j++) {
                    for (int k = 0; k < b; k++) {
                        arr2[i][j] += arr[i][k] * arr1[k][j];
                    }
                }
            }
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < b; j++) {
                    System.out.print(arr2[i][j] + " ");
                }
                System.out.println();
            }
        } else
            System.out.println("Matrix is not valid");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the operation");
        System.out.println("Press:\n1. Add two matrix\n2. Subtract Two Matrix\n3. Multiply two Matrix\n");
        int x = sc.nextInt();
        System.out.println("Enter number of rows and columns for first Matrix:");
        int a = sc.nextInt();
        int b = sc.nextInt();
        int arr[][] = new int[a][b];
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                arr[i][j] = sc.nextInt();
            }
        }

        System.out.println("Enter number of rows and columns for Second Matrix:");
        int a1 = sc.nextInt();
        int b1 = sc.nextInt();
        int arr1[][] = new int[a][b];
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                arr1[i][j] = sc.nextInt();
            }
        }

        switch (x) {
            case 1:
                addTwoMatrix(arr, a, b, arr1, a1, b1);
                break;
            case 2:
                subtTwoMatrix(arr, a, b, arr1, a1, b1);
                break;
            case 3:
                multi(arr, a, b, arr1, a1, b1);
                break;
        }
        sc.close();
    }
}
