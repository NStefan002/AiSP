#include <iostream>
#include <vector>


using namespace std;

long long brKombinacija(int k, int n);

int main()
{
    int k, n;
    cin >> k >> n;

    cout << brKombinacija(k, n) << endl;

    return 0;
}

long long brKombinacija(int k, int n)
{
    vector<vector<long long>> dp(n + 1);
    for (int i = 0; i <= n; i++)
    {
        dp[i].resize(i + 1, 0);
    }
    // pogledati rekurziju kod memo verzije
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
        for (int j = 1; j < i; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
        dp[i][i] = 1;
    }

    return dp[n][k];
}
