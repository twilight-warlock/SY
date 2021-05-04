import java.util.*;
import java.lang.*;
import java.io.*;

class AllPairShortestPath {
    final static int INF = 99999, V = 4;

    void floydWarshall(int graph[][]) {
        int dist[][] = new int[V][V];
        int i, j, k;

        // Initialize the solution matrix
        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                dist[i][j] = graph[i][j];

        // Adding all vertices one by one to the set of intermediate vertices.
        for (k = 0; k < V; k++) {
            // Picking all vertices as source
            for (i = 0; i < V; i++) {
                // Picking all vertices as destination
                for (j = 0; j < V; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        printSolution(dist);
    }

    void printSolution(int dist[][]) {
        System.out.println("The following matrix shows the shortest " + "distances between every pair of vertices");
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][j] == INF)
                    System.out.print("INF ");
                else
                    System.out.print(dist[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int graph[][] = { { 0, 5, INF, 10 }, { INF, 0, 3, INF }, { INF, INF, 0, 1 }, { INF, INF, INF, 0 } };
        AllPairShortestPath a = new AllPairShortestPath();

        a.floydWarshall(graph);
    }
}
