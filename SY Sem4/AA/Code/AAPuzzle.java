import java.util.Scanner;

public class AAPuzzle {
    public static void main(String args[]) {
        Scanner src = new Scanner(System.in);
        System.out.println("Enter the initial values (enter -1 for blank space): ");
        int [][] mat = new int[4][4];
        int [][] goal = new int[4][4];
        int i_blank=0,j_blank=0;
        for(int i=0;i<4;i++) {
            for (int j = 0; j < 4; j++) {
                mat[i][j] = src.nextInt();
                goal[i][j] = (i*4)+j+1;
                if(mat[i][j]==-1) {
                    i_blank = i;
                    j_blank = j;
                }
            }
        }
        System.out.println("The problem : ");
        printStage(mat);
       branch(mat,i_blank,j_blank,0,-2,goal);
    }
    public static void branch(int[][] a,int x,int y,int inc,int moved_to,int[][] goal){
        if( computeDifferences(a,goal)==0){
            return;
        }
        int final_i = 0;
        int opt_sol = 20;
        int temp[][];
        int temp_i,temp_j;
        for(int i=0;i<4;i++){
            temp = copy_array(a);
            if(Math.abs(i-2)!=moved_to){
                temp_i = x+((i-1)%2);
                temp_j = y+((2-i)%2);
                if(temp_i>=0 && temp_i<4 && temp_j>=0 && temp_j<4) {
                    temp[x][y] = temp[temp_i][temp_j];
                    temp[temp_i][temp_j] = -1;
                    int cost = computeDifferences(temp,goal);
                    if(cost == 0){
                        final_i=i;
                        break;
                    }
                    if(cost<opt_sol){
                        opt_sol = cost;
                        final_i=i;
                    }

                }
            }
        }
        temp_i = x+((final_i-1)%2);
        temp_j = y+((2-final_i)%2);
        a[x][y] = a[temp_i][temp_j];
        a[temp_i][temp_j] = -1;
        inc++;
        System.out.println();
        System.out.println("After stage "+(inc)+": ");
        printStage(a);
        branch(a,temp_i,temp_j,inc,final_i,goal);


    }
    public static int computeDifferences(int[][] a,int [][]b) {
        int count = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (a[i][j] != b[i][j] && a[i][j] != -1)
                    count++;
            }
        }
        return  count;
    }
    public static void printStage(int [][]a){
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                System.out.print(String.format("%2d ",a[i][j]));
            }
            System.out.println();
        }
    }
    public static int[][] copy_array(int[][]a){
        int [][]x = new int[4][4];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                x[i][j] = a[i][j];
            }
        }
        return x;
    }
}


/*

Enter the initial values (enter -1 for blank space):
1
2
3
4
5
6
-1
8
9
10
7
11
13
14
15
12
The problem :
 1  2  3  4
 5  6 -1  8
 9 10  7 11
13 14 15 12

After stage1:
 1  2  3  4
 5  6  7  8
 9 10 -1 11
13 14 15 12

After stage2:
 1  2  3  4
 5  6  7  8
 9 10 11 -1
13 14 15 12

After stage3:
 1  2  3  4
 5  6  7  8
 9 10 11 12
13 14 15 -1

Process finished with exit code 0

 */



/*
Enter the initial values (enter -1 for blank space):
1
2
3
4
5
6
11
7
9
10
-1
8
13
14
15
12
The problem :
 1  2  3  4
 5  6 11  7
 9 10 -1  8
13 14 15 12

After stage 1:
 1  2  3  4
 5  6 -1  7
 9 10 11  8
13 14 15 12

After stage 2:
 1  2  3  4
 5  6  7 -1
 9 10 11  8
13 14 15 12

After stage 3:
 1  2  3  4
 5  6  7  8
 9 10 11 -1
13 14 15 12

After stage 4:
 1  2  3  4
 5  6  7  8
 9 10 11 12
13 14 15 -1

Process finished with exit code 0
 */

