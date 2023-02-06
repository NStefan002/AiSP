#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int editRastojanje(string &s1, string &s2, int umetanje, int brisanje, int izmena);
int editRastojanjeMemOptimizovano(string &s1, string &s2, int umetanje, int brisanje, int izmena);

int main()
{
    string s1, s2;
    int umetanje, brisanje, izmena;
    cin >> s1 >> s2 >> umetanje >> brisanje >> izmena;

    cout << editRastojanje(s1, s2, umetanje, brisanje, izmena) << endl;
    cout << editRastojanjeMemOptimizovano(s1, s2, umetanje, brisanje , izmena) << endl;

    return 0;
}

int editRastojanje(string &s1, string &s2, int umetanje, int brisanje, int izmena)
{
    int n1 = s1.length();
    int n2 = s2.length();

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));

    dp[0][0] = 0;
    for (int i = 0; i <= n1; i++)
    {
        dp[i][0] = i * brisanje;
    }

    for (int j = 0; j <= n2; j++)
    {
        dp[0][j] = j * umetanje;
    }

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                int promena1 = dp[i - 1][j] + umetanje;
                int promena2 = dp[i][j - 1] + brisanje;
                int promena3 = dp[i - 1][j - 1] + izmena;
                dp[i][j] = min({promena1, promena2, promena3});
            }
        }
    }

    return dp[n1][n2];
}

int editRastojanjeMemOptimizovano(string &s1, string &s2, int umetanje, int brisanje, int izmena)
{
    int n1 = s1.length();
    int n2 = s2.length();

    vector<int> dp(n2 + 1);
    for (int j = 0; j <= n2; j++)
    {
        dp[j] = j * umetanje;
    }

    for (int i = 1; i <= n1; i++)
    {
        int prethodni = dp[0];
        dp[0] = i * brisanje;

        for (int j = 1; j <= n2; j++)
        {
            int tekuci = dp[j];
            if (s1[i - 1] == s2[j - 1])
            {
                dp[j] = prethodni;
            }
            else
            {
                int promena1 = tekuci + umetanje;
                int promena2 = dp[j - 1] + brisanje;
                int promena3 = prethodni + izmena;
                dp[j] = min({promena1, promena2, promena3});
            }
            prethodni = tekuci;
        }
    }

    return dp[n2];
}
