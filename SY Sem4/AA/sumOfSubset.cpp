#include <bits/stdc++.h>

#define rep(i, n) for (int(i) = 0; (i) < (int)(n); ++(i))
#define reu(i, l, u) for (int(i) = (int)(l); (i) < (int)(u); ++(i))
#define each(it, o) for (auto it = (o).begin(); it != (o).end(); ++it)
#define ios                   \
    freopen("i", "r", stdin); \
    freopen("o", "w", stdout);

using namespace std;

int n;

void sumofsubsets(int s, int m, int k, int r, int arr[], int X[])
{
    X[k] = 1;
    if (k < n)
    {
        if (s + arr[k] == m)
        {
            rep(i, n)
            {
                if (X[i] == 1)
                {
                    X[i] = 0;
                    cout << arr[i] << " ";
                }
            }
            cout << endl;
            return;
        }
        if (k < n - 1)
        {
            if (s + arr[k] + arr[k + 1] <= m)
            {
                sumofsubsets(s + arr[k], m, k + 1, r - arr[k], arr, X);
            }
            if (s + r - arr[k] >= m && s + arr[k + 1] <= m)
            {
                X[k] = 0;
                sumofsubsets(s, m, k + 1, r - arr[k], arr, X);
            }
        }
    }
    else
    {
        cout << "Not found\n";
        return;
    }
}

int main()
{
    ios
            cin >>
        n;
    int r = 0, m, s = 0;
    int arr[n];
    int X[n];
    cin >> m;
    rep(i, n)
    {
        cin >> arr[i];
        r += arr[i];
        X[i] = 0;
    }
    sort(arr, arr + n);
    sumofsubsets(s, m, 0, r, arr, X);
}
