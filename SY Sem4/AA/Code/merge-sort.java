import java.util.Arrays;

public class AALabMergeSort2 {
    public static void main(String args[]) {
        int i = 0, j = 0, k = 0;
        int[] arr = { 1, 5, 2, 4, 7, 3, 2, 8 };
        sort(arr);

        System.out.println("\n\nFinal result :-" + Arrays.toString(arr));
    }

    public static void sort(int[] arr) {

        if (arr.length <= 1)
            return;
        int middle = arr.length / 2;
        int[] left = new int[middle];
        int[] right = new int[arr.length - middle];
        int i;
        // splitting the array
        for (i = 0; i < middle; i++)
            left[i] = arr[i];
        for (i = middle; i < arr.length; i++)
            right[i - middle] = arr[i];
        System.out.println("\narray to be splitted:- " + Arrays.toString(arr));
        System.out.println("splitted arrays :- \tleft" + Arrays.toString(left) + "\tright" + Arrays.toString(right));
        sort(left);
        sort(right);
        merge(left, right, arr);
    }

    public static void merge(int[] left, int[] right, int[] resarr) {
        int i = 0, k = 0, j = 0;
        // comparing individual elements from left and right arrays and appending it to
        // result array
        while (left.length > i && right.length > j) {
            if (left[i] >= right[j])
                resarr[k++] = right[j++];
            else
                resarr[k++] = left[i++];
        }
        // appneding the remaining items to result array
        while (left.length > i)
            resarr[k++] = left[i++];
        while (right.length > j)
            resarr[k++] = right[j++];
        System.out.println("Merged array:- " + Arrays.toString(resarr));
    }
}