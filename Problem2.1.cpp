#include <bits/stdc++.h>
using namespace std;

const int N = 760;
int n, m;
long long int firstEnergy[N][N];
bool used[N][N];

void fW()
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((firstEnergy[i][j] > (firstEnergy[i][k] + firstEnergy[k][j])) && (firstEnergy[i][k] != INT_MAX && firstEnergy[k][j] != INT_MAX))
                {
                    firstEnergy[i][j] = firstEnergy[i][k] + firstEnergy[k][j];
                    // used[i][j] = true;
                }
                // if (used[i][j] == false && (used[i][k] == true && used[k][j] == true))
                // {
                //     firstEnergy[i][j] = firstEnergy[i][k] + firstEnergy[k][j];
                //     used[i][j] = true;
                // }
            }
        }
    }
    long long int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // cout << firstEnergy[i][j] << ' ';
            ans += firstEnergy[i][j];
        }
        // cout << endl;
    }
    cout << ans << endl;
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            firstEnergy[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        firstEnergy[a - 1][b - 1] = c;
        used[a - 1][b - 1] = true;
    }
    for (int i = 0; i < n; i++)
    {
        firstEnergy[i][i] = 0;
        used[i][i] = true;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << firstEnergy[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    fW();
    return 0;
}
