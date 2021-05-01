#include <bits/stdc++.h>

#define rep(i, n) for (int(i) = 0; (i) < (int)(n); ++(i))
#define reu(i, l, u) for (int(i) = (int)(l); (i) < (int)(u); ++(i))
#define each(it, o) for (auto it = (o).begin(); it != (o).end(); ++it)
#define ios                   \
    freopen("i", "r", stdin); \
    freopen("o", "w", stdout);
#define INF 99999

using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void display(int dist[][100], int size, int step)
{
    int n = size;
    cout << "Step " << step << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF"
                     << "     ";
            else
                cout << dist[i][j] << "     ";
        }
        cout << endl;
    }
}

void floyd(int graph[][100], int size)
{
    int n = size;
    int dist[size][100], i, j, k;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {

            for (j = 0; j < n; j++)
            {

                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
        display(dist, n, k + 1);
    }
}

int main()
{
    ios int n;
    cout << "Enter number: ";
    cin >> n;
    int graph[100][100];
    rep(i, n)
    {
        rep(j, n)
        {
            if (i == j)
            {
                graph[i][j] = 0;
                continue;
            }
            graph[i][j] = INF;
        }
    }
    int a, b, weight;
    while (cin >> a >> b >> weight)
    {
        if (a == b)
            continue;
        if (a < 0 || a >= n)
            continue;
        if (b < 0 || b >= n)
            continue;
        graph[a][b] = weight;
        graph[b][a] = weight;
    }
    floyd(graph, n);
    return 0;
}
