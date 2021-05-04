#include <bits/stdc++.h>

#define rep(i, n) for (int(i) = 0; (i) < (int)(n); ++(i))
#define reu(i, l, u) for (int(i) = (int)(l); (i) < (int)(u); ++(i))
#define each(it, o) for (auto it = (o).begin(); it != (o).end(); ++it)
#define ios                   \
    freopen("i", "r", stdin); \
    freopen("o", "w", stdout);

using namespace std;

bool comp(int a, int b)
{
    return (a < b);
}

void display(int arr[], int n)
{
    rep(i, n)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap_char(char x, chary)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    ios
        string a,
        b;
    cin >> a >> b;

    int n = a.size();
    int m = b.size();

    int L[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    int index = L[n][m];
    string lcs;
    lcs.resize(index);

    int i = n, j = m;

    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            lcs[index - 1] = a[i - 1];
            i--;
            j--;
            index--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }
    cout << "LCS of " << a << " and " << b << " is " << lcs;
}