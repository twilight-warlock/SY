import java.util.Arrays;
import java.util.Scanner;

public class SOS {
    public static void main(String args[]) {
        Scanner src = new Scanner(System.in);
        System.out.println("Enter the total number of values: ");
        int n = src.nextInt();
        int values[] = new int[n];
        int x[]  = new int[n];
        for(int i=0;i<n;i++){
            System.out.println("Enter the values: ");
            values[i] = src.nextInt();
        }
        Arrays.sort(values);
        System.out.println("Enter the needed sum : ");
        int need_sum = src.nextInt();
        int rem = sum(values);
        System.out.println("The subsets are as follows: ");
        subset_sum(values,need_sum,x,0,0,rem);

    }
    public static int sum(int []a){
        int x=0;
        for(int i=0;i<a.length;i++){
            x+=a[i];
        }
        return x;
    }
    public static void subset_sum(int []a,int b,int []x,int s,int k,int r){

        if(s==b){
            System.out.println();
            System.out.print("{");
            for(int i=0;i<x.length;i++){
                if(x[i]==1){
                    System.out.print(String.format("%d ",a[i]));
                }
            }
            System.out.print("}");
            x[k-1]=0;
            return;
        }
        else if(s+a[k]<=b){
            x[k] = 1;
            subset_sum(a,b,x,s+a[k],k+1,r-a[k]);
        }
        if (s+r-a[k] >= b && s<=b){
            x[k] = 0;
            subset_sum(a,b,x,s,k+1,r-a[k]);
        }

    }
}

/*

Enter the total number of values:
7
Enter the values:
10
Enter the values:
7
Enter the values:
5
Enter the values:
18
Enter the values:
12
Enter the values:
20
Enter the values:
15
Enter the needed sum :
35
The subsets are as follows:

{5 10 20 }
{5 12 18 }
{7 10 18 }
{15 20 }

 */