
import java.util.Scanner;

public class AALC1 {
    public static class char_of_seq {
        int i_index;
        int j_index;
        int value;

        char_of_seq() {
            this.i_index = -1;
            this.j_index = -1;
            this.value = 0;
        }
    }

    public static void main(String args[]) {
        Scanner src = new Scanner(System.in);
        System.out.println("Enter the first string");
        String a = src.next();
        System.out.println("Enter the second string");
        String b = src.next();
        int a_len = a.length(), b_len = b.length();
        char_of_seq[][] mat = new char_of_seq[a_len + 1][b_len + 1];
        int lcs_len = gen_matrix(mat, a, b);
        System.out.println(print_lcs(lcs_len, mat, a, b));

    }

    public static int gen_matrix(char_of_seq[][] mat, String a, String b) {
        int a_len = a.length(), b_len = b.length();
        // assign 0 to 1st column
        for (int i = 0; i <= a_len; i++) {
            mat[i][0] = new char_of_seq();
            mat[i][0].value = 0;
        }
        //assign 0 to 1st row
        for (int j = 0; j <= b_len; j++) {
            mat[0][j] = new char_of_seq();
            mat[0][j].value = 0;
        }
        for (int i = 1; i <= a_len; i++) {
            for (int j = 1; j <= b_len; j++) {
                mat[i][j] = new char_of_seq();
                if (a.charAt(i - 1) == b.charAt(j - 1)) {
                    mat[i][j].value = mat[i - 1][j - 1].value + 1;
                    mat[i][j].i_index = i - 1;
                    mat[i][j].j_index = j - 1;
                } else if (mat[i - 1][j].value <= mat[i][j - 1].value) {
                    mat[i][j].value = mat[i][j - 1].value;
                    mat[i][j].i_index = i;
                    mat[i][j].j_index = j - 1;
                } else {
                    mat[i][j].value = mat[i - 1][j].value;
                    mat[i][j].i_index = i - 1;
                    mat[i][j].j_index = j;

                }
            }
        }
        System.out.println("The matrix is :");
        for (int i = 0; i <= a_len; i++) {
            System.out.println();
            for (int j = 0; j <= b_len; j++) {
                System.out.print(mat[i][j].value + " ");
            }
        }

        return mat[a_len][b_len].value;
    }

    public static String print_lcs(int lcs_len, char_of_seq[][] mat, String a, String b) {
        char lcs_chars[] = new char[lcs_len];
        if (lcs_len == 0) {
            System.out.println("No subsequence found");
        } else {

            System.out.println();
            System.out.println("The length of longest common subseq is:" + lcs_len);
            System.out.println("The longest common subseq is:");
            int i =a.length(), j = b.length();
            while (lcs_len > 0) {
                int derived_from_i = mat[i][j].i_index, derived_from_j = mat[i][j].j_index;
                if (mat[i][j].value == mat[derived_from_i][derived_from_j].value + 1) {
                    lcs_chars[--lcs_len] = a.charAt(i - 1);
                }
                i = derived_from_i;
                j = derived_from_j;


            }
        }
        return new String(lcs_chars);
    }
}
//ABCBDAB
//BDCABA

//ABCBDAB
//BDCABA
