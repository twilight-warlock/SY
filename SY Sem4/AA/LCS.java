import java.io.*;
import java.util.Scanner;

public class LCS {

    // Returns length of LCS for X[0..m-1], Y[0..n-1]
    int lcs(char[] X, char[] Y, int m, int n) {
        if (m == 0 || n == 0)
            return 0;
        if (X[m - 1] == Y[n - 1])
            return 1 + lcs(X, Y, m - 1, n - 1);
        else
            return Math.max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n));
    }

    String lcsChar(char[] X, char[] Y, int m, int n) {
        int L[][] = new int[m + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0)
                    L[i][j] = 0;
                else if (X[i - 1] == Y[j - 1])
                    L[i][j] = L[i - 1][j - 1] + 1;
                else
                    L[i][j] = Math.max(L[i - 1][j], L[i][j - 1]);
            }
        }

        int index = L[n][m];
        char lcs2[] = new char[index];

        int i = n, j = m;

        // Printing
        while (i > 0 && j > 0) {
            if (X[i - 1] == Y[j - 1]) {
                lcs2[index - 1] = X[i - 1];
                i--;
                j--;
                index--;
            } else if (L[i - 1][j] > L[i][j - 1])
                i--;
            else
                j--;
        }

        return String.valueOf(lcs2);
    }

    public static void main(String[] args) {
        LCS lcs = new LCS();

        Scanner ob = new Scanner(System.in);

        System.out.println("Enter 1st String : ");
        String s1 = ob.next();
        System.out.println("Enter 2nd String : ");
        String s2 = ob.next();

        char[] X = s1.toCharArray();
        char[] Y = s2.toCharArray();
        int m = X.length;
        int n = Y.length;

        System.out.println("Strings of LCS is" + " " + lcs.lcsChar(X, Y, m, n));
        System.out.println("Length of LCS is" + " " + lcs.lcs(X, Y, m, n));
    }

}
