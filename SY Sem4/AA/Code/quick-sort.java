import java.io.*;
import java.util.Scanner;

class ABC2 {
    static int a[];

    public static void quickSort(int lb, int ub) {
        if (lb < ub) {
            int j = partition(lb, ub);
            quickSort(lb, j - 1);
            quickSort(j + 1, ub);
        }
    }

    public static int partition(int lb, int ub) {
        int pivot = a[lb];
        int i = lb, j = ub;
        while (i < j) {
            while (a[i] <= pivot) {
                i++;
            }
            while (a[j] > pivot) {
                j--;
            }
            if (i < j) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        int temp2 = a[j];
        a[j] = a[lb];
        a[lb] = temp2;
        return j;
    }

    // Driver code
    public static void main(String[] args) {

        Scanner ob = new Scanner(System.in);
        System.out.println("Enter number of elements: ");
        int n = ob.nextInt();
        a = new int[n];
        for (int i = 0; i < n; i++) {
            System.out.print("Enter element no." + (i + 1) + ": ");
            a[i] = ob.nextInt();
        }

        int left = 0, right = n - 1;
        quickSort(left, right);

        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i] + " ");
        }
    }
}
