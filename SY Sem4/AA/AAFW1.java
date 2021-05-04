import java.util.Formatter;
import java.util.Scanner;

public class AAFW1 {
    public static void main(String args[]) {
        Scanner src = new Scanner(System.in);
        System.out.println("Enter the total number of nodes: ");
        int n = src.nextInt();
        System.out.println("Enter the total number of unidirectd edges:");
        int n_edges = src.nextInt();
        int [][] input_graph = new int[n][n];

        int [][] dist_graph = new int[n][n];
        int [][] p = new int[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                p[i][j] = 0;
                continue;
            }
            p[i][j]=-1;
        }
    }
        initializeGraph(input_graph);
        System.out.println("Enter the two end nodes connected by an edge and the corresponding weight: ");
        for(int i=0;i<n_edges;i++){
            int x = src.nextInt();
            int y = src.nextInt();
            input_graph[x-1][y-1] = src.nextInt();
            p[x-1][y-1] = x;
        }
        System.out.println("The given input matrix is :");
        printGraph(input_graph,n);
        System.out.println("");
        generateDistanceGraph(dist_graph,input_graph,p);

    }
    public static void initializeGraph(int [][]a){
        for(int i=0;i<a.length;i++){
            for(int j=0;j<a.length;j++){
                if(i==j)
                    a[i][j]=0;
                else
                    a[i][j] = 100000;
            }
        }

    }
    public static void initializeDistGraph(int [][]a,int[][] x) {
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a.length; j++) {
                a[i][j] = x[i][j];
            }
        }
    }

    public static void generateDistanceGraph(int [][]a,int [][] b,int[][]p){
        initializeDistGraph(a,b);
        int n = a.length;

        for (int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                if(i==via) {
                    continue;
                }
                for(int j=0;j<n;j++) {
                    if(j==via)
                        continue;
                    if(a[i][j]>(a[i][via]+a[via][j])){
                        a[i][j] = a[i][via]+a[via][j];
                        p[i][j] = p[via][j];
                    }
                }
            }
            printDistanceGraph(a,n,via);
            printDistanceGraph(p,n,via);
        }


    }
    public static void printGraph(int [][]a,int n) {
        for (int i = 0; i < n; i++) {
            System.out.println();
            for (int j = 0; j < n; j++) {
                System.out.print(String.format("%9d",a[i][j]));

            }
        }
    }

    public static void printDistanceGraph(int [][]a,int n,int via) {
        System.out.println("For " + (via + 1) + ": ");
        for (int i = 0; i < n; i++) {
            System.out.println();
            for (int j = 0; j < n; j++) {
                System.out.print(String.format("%9d",a[i][j]));

            }
        }
        System.out.println();
    }
}


/*

4 0 1
4 1 3
0 1 5
1 2 2
3 2 4
3 4 1
2 0 3
0 3 2
2 4 7

 */
/*
5 1 1
5 2 3
1 2 5
2 3 2
4 3 4
4 5 1
3 1 3
1 4 2
3 5 7
 */

/*
1 2 3
1 3 8
1 5 -4
2 4 1
2 5 7
3 2 4
3 4 -5
4 1 2
5 4 6
 */