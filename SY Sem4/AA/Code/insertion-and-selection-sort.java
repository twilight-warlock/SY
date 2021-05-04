import java.io.*;
import java.util.Scanner;

class ABC {
    static int a[];
    static int innerCount = 0, outerCount = 0;

    public static void insertion() {
        int key, i;
        for (int j = 1; j < a.length; j++) {
            key = a[j];
            i = j - 1;
            while (i >= 0 && a[i] > key) {
                a[i + 1] = a[i];
                i = i - 1;
                innerCount++;
            }
            a[i + 1] = key;
            outerCount++;
        }
    }

    public static void selection() {
        int min;
        for (int i = 0; i < a.length; i++) {
            min = i;
            for (int j = i + 1; j < a.length; j++) {
                if (a[j] < a[min]) {
                    min = j;
                }
                innerCount++;
            }
            if (min != i) {
                int temp = a[min];
                a[min] = a[i];
                a[i] = temp;
            }
            outerCount++;
        }
    }

    // Driver code
    public static void main(String[] args) {

        Scanner ob = new Scanner(System.in);
        System.out.println("Enter number of elements: ");
        int n = ob.nextInt();
        System.out.println("\n1.Best case\n2.Worst case\nEnter choice from 1-2: ");
        int chnum = ob.nextInt();

        a = new int[n];

        if (chnum == 1) {
            for (int i = 0; i < n; i++) {
                a[i] = i + 1;
            }
        } else {
            int j = n;
            for (int i = 0; i < n; i++) {
                a[i] = j;
                j--;
            }
        }
        System.out.print("\n1.Insertion\n2.Selection\nEnter the coice from 1-2: ");
        int ch = ob.nextInt();
        switch (ch) {
            case 1:
                insertion();
                System.out.println("The output via insertion sort");
                break;
            case 2:
                selection();
                System.out.println("The output via selection sort");
                break;
            default:
                System.out.println("Incorrect choice");
                System.exit(0);
        }

        for (int i = 0; i < n; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println("\nInner loop: " + innerCount);
        System.out.println("Outer loop: " + outerCount);
    }
}
